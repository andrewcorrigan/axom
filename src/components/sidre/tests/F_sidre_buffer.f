!
! Copyright (c) 2015, Lawrence Livermore National Security, LLC.
! Produced at the Lawrence Livermore National Laboratory.
!
! All rights reserved.
!
! This source code cannot be distributed without permission and
! further review from Lawrence Livermore National Laboratory.
!

module sidre_buffer
  use iso_c_binding
  use fruit
  use sidre_mod
  implicit none

contains
!------------------------------------------------------------------------------

  subroutine create_buffers
    type(datastore) ds
    type(databuffer) dbuff_0, dbuff_1, dbuff_3

    call set_case_name("create_buffers")

    ds = datastore_new()

    dbuff_0 = ds%create_buffer()
    dbuff_1 = ds%create_buffer()

    call assert_equals(dbuff_0%get_index(), 0, "dbuff_0%get_index()")
    call assert_equals(dbuff_1%get_index(), 1, "dbuff_1%get_index()")
    call ds%destroy_buffer(0)

    dbuff_3 = ds%create_buffer()
    call assert_equals(dbuff_3%get_index(), 0, "dbuff_3%get_index()")

    call ds%print()
    call ds%delete()
  end subroutine create_buffers

!------------------------------------------------------------------------------

  subroutine alloc_buffer_for_int_array
    type(datastore) ds
    type(databuffer) dbuff
    type(C_PTR) data_ptr
    integer(C_INT), pointer :: data(:)
    integer i
    
    call set_case_name("alloc_buffer_for_int_array")

    ds = datastore_new()
    dbuff = ds%create_buffer()

    call dbuff%allocate(SIDRE_INT_ID, 10_8)

    call assert_equals(dbuff%get_type_id(), SIDRE_INT_ID, "dbuff%get_typeid()")
    call assert_true(dbuff%get_num_elements() == 10, "dbuff%get_num_elements()")
!    call assert_equals(dbuff%get_total_bytes(), sizeof(int) * 10)

    data_ptr = dbuff%get_void_ptr()
    call c_f_pointer(data_ptr, data, [ 10 ])

    do i = 1, 10
       data(i) = i * i
    enddo

    call dbuff%print()

    call ds%print()
    call ds%delete()
  end subroutine alloc_buffer_for_int_array

!------------------------------------------------------------------------------

  subroutine init_buffer_for_int_array
    type(datastore) ds
    type(databuffer) dbuff
    type(C_PTR) data_ptr
    integer(C_INT), pointer :: data(:)
    integer i

    call set_case_name("init_buffer_for_int_array")

    ds = datastore_new()
    dbuff = ds%create_buffer()

    call dbuff%allocate(SIDRE_INT_ID, 10_8)

    call assert_equals(dbuff%get_type_id(), SIDRE_INT_ID, "dbuff%get_type_id()")
    call assert_true(dbuff%get_num_elements() == 10, "dbuff%get_num_elements")
!    call assert_equals(dbuff%get_total_bytes(), sizeof(int) * 10)

    data_ptr = dbuff%get_void_ptr()
    call c_f_pointer(data_ptr, data, [ 10 ])

    do i = 1, 10
       data(i) = i * i
    enddo

    call dbuff%print()

    call ds%print()
    call ds%delete()
  end subroutine init_buffer_for_int_array

!------------------------------------------------------------------------------

  subroutine realloc_buffer
    type(datastore) ds
    type(databuffer) dbuff
    type(C_PTR) data_ptr
    integer(C_LONG), pointer :: data(:)
    integer i

    call set_case_name("realloc_buffer")

    ds = datastore_new()

    dbuff = ds%create_buffer()

    call dbuff%allocate(SIDRE_LONG_ID, 5_8)

    call assert_equals(dbuff%get_type_id(), SIDRE_LONG_ID, "dbuff%get_type_id()")
    call assert_true(dbuff%get_num_elements() == 5, "dbuff%get_num_elements()")
!    call assert_equals(dbuff%get_total_bytes(), sizeof(long) * 10)

    data_ptr = dbuff%get_void_ptr()
    call c_f_pointer(data_ptr, data, [ 5 ])

    data(:) = 5

    call dbuff%print()
  
    call dbuff%reallocate(10)

    call assert_equals(dbuff%get_type_id(), SIDRE_LONG_ID, "dbuff%get_type_id() after realloc")
    call assert_true(dbuff%get_num_elements() == 10, "dbuff%get_num_elments() after realloc")
!    call assert_equals(dbuff%get_total_bytes(), sizeof(long) * 10)

    ! data buffer changes
    data_ptr = dbuff%get_void_ptr()
    call c_f_pointer(data_ptr, data, [ 10 ])

    call assert_true(size(data) == 10, "data_ptr is wrong size")
    call assert_true(all(data(1:5) == 5), "data has wrong values")

    data(6:10) = 10

    call dbuff%print()

    call ds%print()
    call ds%delete()
  end subroutine realloc_buffer

!----------------------------------------------------------------------
end module sidre_buffer
!----------------------------------------------------------------------

program fortran_test
  use fruit
  use sidre_buffer
  implicit none
  logical ok

  call init_fruit

  call create_buffers
  call alloc_buffer_for_int_array
  call init_buffer_for_int_array
  call realloc_buffer

  call fruit_summary
  call fruit_finalize

  call is_all_successful(ok)
  if (.not. ok) then
     call exit(1)
  endif
end program fortran_test