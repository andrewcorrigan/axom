! wrapftutorial.f
! This is generated code, do not edit
!>
!! \file wrapftutorial.f
!! \brief Shroud generated wrapper for Tutorial library
!<
module tutorial_mod
    use, intrinsic :: iso_c_binding, only : C_PTR
    ! splicer begin module_use
    ! splicer end module_use
    ! splicer begin class.Class1.module_use
    ! splicer end class.Class1.module_use
    implicit none
    
    ! splicer begin module_top
    ! splicer end module_top
    
    ! splicer begin class.Class1.module_top
    ! splicer end class.Class1.module_top
    
    type class1
        type(C_PTR), private :: voidptr
        ! splicer begin class.Class1.component_part
        ! splicer end class.Class1.component_part
    contains
        procedure :: delete => class1_delete
        procedure :: method1 => class1_method1
        procedure :: get_instance => class1_get_instance
        procedure :: set_instance => class1_set_instance
        procedure :: associated => class1_associated
        ! splicer begin class.Class1.type_bound_procedure_part
        ! splicer end class.Class1.type_bound_procedure_part
    end type class1
    
    
    interface operator (.eq.)
        module procedure class1_eq
    end interface
    
    interface operator (.ne.)
        module procedure class1_ne
    end interface
    
    interface
        
        function c_class1_new() &
                result(rv) &
                bind(C, name="TUT_class1_new")
            use iso_c_binding
            implicit none
            type(C_PTR) :: rv
        end function c_class1_new
        
        subroutine c_class1_delete(self) &
                bind(C, name="TUT_class1_delete")
            use iso_c_binding
            implicit none
            type(C_PTR), value, intent(IN) :: self
        end subroutine c_class1_delete
        
        subroutine c_class1_method1(self) &
                bind(C, name="TUT_class1_method1")
            use iso_c_binding
            implicit none
            type(C_PTR), value, intent(IN) :: self
        end subroutine c_class1_method1
        
        ! splicer begin class.Class1.additional_interfaces
        ! splicer end class.Class1.additional_interfaces
        
        subroutine function1() &
                bind(C, name="TUT_function1")
            use iso_c_binding
            implicit none
        end subroutine function1
        
        function function2(arg1, arg2) &
                result(rv) &
                bind(C, name="TUT_function2")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg1
            integer(C_INT), value, intent(IN) :: arg2
            real(C_DOUBLE) :: rv
        end function function2
        
        subroutine sum(len, values, result) &
                bind(C, name="TUT_sum")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: len
            integer(C_INT), intent(IN) :: values(*)
            integer(C_INT), intent(OUT) :: result
        end subroutine sum
        
        function c_function3(arg) &
                result(rv) &
                bind(C, name="TUT_function3")
            use iso_c_binding
            implicit none
            logical(C_BOOL), value, intent(IN) :: arg
            logical(C_BOOL) :: rv
        end function c_function3
        
        subroutine c_function4a_bufferify(arg1, Larg1, arg2, Larg2, SH_F_rv, LSH_F_rv) &
                bind(C, name="TUT_function4a_bufferify")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Larg1
            character(kind=C_CHAR), intent(IN) :: arg2(*)
            integer(C_INT), value, intent(IN) :: Larg2
            character(kind=C_CHAR), intent(OUT) :: SH_F_rv(*)
            integer(C_INT), value, intent(IN) :: LSH_F_rv
        end subroutine c_function4a_bufferify
        
        function c_function4b(arg1, arg2) &
                result(rv) &
                bind(C, name="TUT_function4b")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            character(kind=C_CHAR), intent(IN) :: arg2(*)
            type(C_PTR) rv
        end function c_function4b
        
        subroutine c_function4b_bufferify(arg1, Larg1, arg2, Larg2, output, Loutput) &
                bind(C, name="TUT_function4b_bufferify")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Larg1
            character(kind=C_CHAR), intent(IN) :: arg2(*)
            integer(C_INT), value, intent(IN) :: Larg2
            character(kind=C_CHAR), intent(OUT) :: output(*)
            integer(C_INT), value, intent(IN) :: Loutput
        end subroutine c_function4b_bufferify
        
        function c_function5() &
                result(rv) &
                bind(C, name="TUT_function5")
            use iso_c_binding
            implicit none
            real(C_DOUBLE) :: rv
        end function c_function5
        
        function c_function5_arg1(arg1) &
                result(rv) &
                bind(C, name="TUT_function5_arg1")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg1
            real(C_DOUBLE) :: rv
        end function c_function5_arg1
        
        function c_function5_arg1_arg2(arg1, arg2) &
                result(rv) &
                bind(C, name="TUT_function5_arg1_arg2")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg1
            logical(C_BOOL), value, intent(IN) :: arg2
            real(C_DOUBLE) :: rv
        end function c_function5_arg1_arg2
        
        subroutine c_function6_from_name(name) &
                bind(C, name="TUT_function6_from_name")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
        end subroutine c_function6_from_name
        
        subroutine c_function6_from_name_bufferify(name, Lname) &
                bind(C, name="TUT_function6_from_name_bufferify")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
            integer(C_INT), value, intent(IN) :: Lname
        end subroutine c_function6_from_name_bufferify
        
        subroutine c_function6_from_index(indx) &
                bind(C, name="TUT_function6_from_index")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: indx
        end subroutine c_function6_from_index
        
        subroutine c_function7_int(arg) &
                bind(C, name="TUT_function7_int")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: arg
        end subroutine c_function7_int
        
        subroutine c_function7_double(arg) &
                bind(C, name="TUT_function7_double")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg
        end subroutine c_function7_double
        
        function c_function8_int() &
                result(rv) &
                bind(C, name="TUT_function8_int")
            use iso_c_binding
            implicit none
            integer(C_INT) :: rv
        end function c_function8_int
        
        function c_function8_double() &
                result(rv) &
                bind(C, name="TUT_function8_double")
            use iso_c_binding
            implicit none
            real(C_DOUBLE) :: rv
        end function c_function8_double
        
        subroutine c_function9(arg) &
                bind(C, name="TUT_function9")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg
        end subroutine c_function9
        
        subroutine c_function10_0() &
                bind(C, name="TUT_function10_0")
            use iso_c_binding
            implicit none
        end subroutine c_function10_0
        
        subroutine c_function10_1(name, arg2) &
                bind(C, name="TUT_function10_1")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
            real(C_DOUBLE), value, intent(IN) :: arg2
        end subroutine c_function10_1
        
        subroutine c_function10_1_bufferify(name, Lname, arg2) &
                bind(C, name="TUT_function10_1_bufferify")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
            integer(C_INT), value, intent(IN) :: Lname
            real(C_DOUBLE), value, intent(IN) :: arg2
        end subroutine c_function10_1_bufferify
        
        function c_overload1_num(num) &
                result(rv) &
                bind(C, name="TUT_overload1_num")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT) :: rv
        end function c_overload1_num
        
        function c_overload1_num_offset(num, offset) &
                result(rv) &
                bind(C, name="TUT_overload1_num_offset")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT), value, intent(IN) :: offset
            integer(C_INT) :: rv
        end function c_overload1_num_offset
        
        function c_overload1_num_offset_stride(num, offset, stride) &
                result(rv) &
                bind(C, name="TUT_overload1_num_offset_stride")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT), value, intent(IN) :: offset
            integer(C_INT), value, intent(IN) :: stride
            integer(C_INT) :: rv
        end function c_overload1_num_offset_stride
        
        function c_overload1_3(type, num) &
                result(rv) &
                bind(C, name="TUT_overload1_3")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: type
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT) :: rv
        end function c_overload1_3
        
        function c_overload1_4(type, num, offset) &
                result(rv) &
                bind(C, name="TUT_overload1_4")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: type
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT), value, intent(IN) :: offset
            integer(C_INT) :: rv
        end function c_overload1_4
        
        function c_overload1_5(type, num, offset, stride) &
                result(rv) &
                bind(C, name="TUT_overload1_5")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: type
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT), value, intent(IN) :: offset
            integer(C_INT), value, intent(IN) :: stride
            integer(C_INT) :: rv
        end function c_overload1_5
        
        function typefunc(arg) &
                result(rv) &
                bind(C, name="TUT_typefunc")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: arg
            integer(C_INT) :: rv
        end function typefunc
        
        function enumfunc(arg) &
                result(rv) &
                bind(C, name="TUT_enumfunc")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: arg
            integer(C_INT) :: rv
        end function enumfunc
        
        subroutine c_useclass(arg1) &
                bind(C, name="TUT_useclass")
            use iso_c_binding
            implicit none
            type(C_PTR), value, intent(IN) :: arg1
        end subroutine c_useclass
        
        pure function c_last_function_called() &
                result(rv) &
                bind(C, name="TUT_last_function_called")
            use iso_c_binding
            implicit none
            type(C_PTR) rv
        end function c_last_function_called
        
        subroutine c_last_function_called_bufferify(SH_F_rv, LSH_F_rv) &
                bind(C, name="TUT_last_function_called_bufferify")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SH_F_rv(*)
            integer(C_INT), value, intent(IN) :: LSH_F_rv
        end subroutine c_last_function_called_bufferify
        
        ! splicer begin additional_interfaces
        subroutine all_test1(array)
          implicit none
          integer, dimension(:), allocatable :: array
        end subroutine all_test1
        ! splicer end additional_interfaces
    end interface
    
    interface function10
        module procedure function10_0
        module procedure function10_1_float
        module procedure function10_1_double
    end interface function10
    
    interface function5
        module procedure function5
        module procedure function5_arg1
        module procedure function5_arg1_arg2
    end interface function5
    
    interface function6
        module procedure function6_from_name
        module procedure function6_from_index
    end interface function6
    
    interface function7
        module procedure function7_int
        module procedure function7_double
    end interface function7
    
    interface function9
        module procedure function9_float
        module procedure function9_double
    end interface function9
    
    interface overload1
        module procedure overload1_num
        module procedure overload1_num_offset
        module procedure overload1_num_offset_stride
        module procedure overload1_3
        module procedure overload1_4
        module procedure overload1_5
    end interface overload1
    
    private fstr, fstr_ptr, fstr_arr, strlen_arr, strlen_ptr
    
    interface fstr
      module procedure fstr_ptr, fstr_arr
    end interface
    
    interface
       pure function strlen_ptr(s) result(result) bind(c,name="strlen")
         use, intrinsic :: iso_c_binding
         integer(c_int) :: result
         type(c_ptr), value, intent(in) :: s
       end function strlen_ptr
    end interface

contains
    
    ! Class1 * new()+constructor
    ! function_index=0
    function class1_new() result(rv)
        implicit none
        type(class1) :: rv
        ! splicer begin class.Class1.method.new
        rv%voidptr = c_class1_new()
        ! splicer end class.Class1.method.new
    end function class1_new
    
    ! void delete()+destructor
    ! function_index=1
    subroutine class1_delete(obj)
        use iso_c_binding, only : C_NULL_PTR
        implicit none
        class(class1) :: obj
        ! splicer begin class.Class1.method.delete
        call c_class1_delete(obj%voidptr)
        obj%voidptr = C_NULL_PTR
        ! splicer end class.Class1.method.delete
    end subroutine class1_delete
    
    ! void Method1()
    ! function_index=2
    subroutine class1_method1(obj)
        implicit none
        class(class1) :: obj
        ! splicer begin class.Class1.method.method1
        call c_class1_method1(obj%voidptr)
        ! splicer end class.Class1.method.method1
    end subroutine class1_method1
    
    function class1_get_instance(obj) result (voidptr)
        use iso_c_binding, only: C_PTR
        implicit none
        class(class1), intent(IN) :: obj
        type(C_PTR) :: voidptr
        voidptr = obj%voidptr
    end function class1_get_instance
    
    subroutine class1_set_instance(obj, voidptr)
        use iso_c_binding, only: C_PTR
        implicit none
        class(class1), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: voidptr
        obj%voidptr = voidptr
    end subroutine class1_set_instance
    
    function class1_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        implicit none
        class(class1), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%voidptr)
    end function class1_associated
    
    ! splicer begin class.Class1.additional_functions
    ! splicer end class.Class1.additional_functions
    
    ! bool Function3(bool arg+intent(in)+value)
    ! function_index=6
    function function3(arg) result(rv)
        use iso_c_binding, only : C_BOOL
        implicit none
        logical, value, intent(IN) :: arg
        logical(C_BOOL) tmp_arg
        logical :: rv
        tmp_arg = arg  ! coerce to C_BOOL
        ! splicer begin function3
        rv = c_function3(tmp_arg)
        ! splicer end function3
    end function function3
    
    ! const std::string Function4a(const std::string & arg1+intent(in), const std::string & arg2+intent(in))
    ! string_to_buffer_and_len
    ! function_index=7
    function function4a(arg1, arg2) result(rv)
        use iso_c_binding, only : C_CHAR, C_INT
        implicit none
        character(*), intent(IN) :: arg1
        character(*), intent(IN) :: arg2
        character(kind=C_CHAR, len=(30)) :: rv
        ! splicer begin function4a
        call c_function4a_bufferify(  &
            arg1,  &
            len_trim(arg1, kind=C_INT),  &
            arg2,  &
            len_trim(arg2, kind=C_INT),  &
            rv,  &
            len(rv, kind=C_INT))
        ! splicer end function4a
    end function function4a
    
    ! void Function4b(const std::string & arg1+intent(in)+len_trim(Larg1), const std::string & arg2+intent(in)+len_trim(Larg2), std::string & output+intent(out)+len(Loutput))
    ! string_to_buffer_and_len - string_to_buffer_and_len
    ! function_index=35
    subroutine function4b(arg1, arg2, output)
        use iso_c_binding, only : C_INT
        implicit none
        character(*), intent(IN) :: arg1
        character(*), intent(IN) :: arg2
        character(*), intent(OUT) :: output
        ! splicer begin function4b
        call c_function4b_bufferify(  &
            arg1,  &
            len_trim(arg1, kind=C_INT),  &
            arg2,  &
            len_trim(arg2, kind=C_INT),  &
            output,  &
            len(output, kind=C_INT))
        ! splicer end function4b
    end subroutine function4b
    
    ! double Function5()
    ! has_default_arg
    ! function_index=23
    function function5() result(rv)
        use iso_c_binding, only : C_DOUBLE
        implicit none
        real(C_DOUBLE) :: rv
        ! splicer begin function5
        rv = c_function5()
        ! splicer end function5
    end function function5
    
    ! double Function5(double arg1+default(3.1415)+intent(in)+value)
    ! has_default_arg
    ! function_index=24
    function function5_arg1(arg1) result(rv)
        use iso_c_binding, only : C_DOUBLE
        implicit none
        real(C_DOUBLE), value, intent(IN) :: arg1
        real(C_DOUBLE) :: rv
        ! splicer begin function5_arg1
        rv = c_function5_arg1(arg1)
        ! splicer end function5_arg1
    end function function5_arg1
    
    ! double Function5(double arg1+default(3.1415)+intent(in)+value, bool arg2+default(true)+intent(in)+value)
    ! function_index=9
    function function5_arg1_arg2(arg1, arg2) result(rv)
        use iso_c_binding, only : C_BOOL, C_DOUBLE
        implicit none
        real(C_DOUBLE), value, intent(IN) :: arg1
        logical, value, intent(IN) :: arg2
        logical(C_BOOL) tmp_arg2
        real(C_DOUBLE) :: rv
        tmp_arg2 = arg2  ! coerce to C_BOOL
        ! splicer begin function5_arg1_arg2
        rv = c_function5_arg1_arg2(  &
            arg1,  &
            tmp_arg2)
        ! splicer end function5_arg1_arg2
    end function function5_arg1_arg2
    
    ! void Function6(const std::string & name+intent(in))
    ! string_to_buffer_and_len
    ! function_index=10
    subroutine function6_from_name(name)
        use iso_c_binding, only : C_INT
        implicit none
        character(*), intent(IN) :: name
        ! splicer begin function6_from_name
        call c_function6_from_name_bufferify(  &
            name,  &
            len_trim(name, kind=C_INT))
        ! splicer end function6_from_name
    end subroutine function6_from_name
    
    ! void Function6(int indx+intent(in)+value)
    ! function_index=11
    subroutine function6_from_index(indx)
        use iso_c_binding, only : C_INT
        implicit none
        integer(C_INT), value, intent(IN) :: indx
        ! splicer begin function6_from_index
        call c_function6_from_index(indx)
        ! splicer end function6_from_index
    end subroutine function6_from_index
    
    ! void Function7(int arg+intent(in)+value)
    ! cpp_template
    ! function_index=25
    subroutine function7_int(arg)
        use iso_c_binding, only : C_INT
        implicit none
        integer(C_INT), value, intent(IN) :: arg
        ! splicer begin function7_int
        call c_function7_int(arg)
        ! splicer end function7_int
    end subroutine function7_int
    
    ! void Function7(double arg+intent(in)+value)
    ! cpp_template
    ! function_index=26
    subroutine function7_double(arg)
        use iso_c_binding, only : C_DOUBLE
        implicit none
        real(C_DOUBLE), value, intent(IN) :: arg
        ! splicer begin function7_double
        call c_function7_double(arg)
        ! splicer end function7_double
    end subroutine function7_double
    
    ! int Function8()
    ! cpp_template
    ! function_index=27
    function function8_int() result(rv)
        use iso_c_binding, only : C_INT
        implicit none
        integer(C_INT) :: rv
        ! splicer begin function8_int
        rv = c_function8_int()
        ! splicer end function8_int
    end function function8_int
    
    ! double Function8()
    ! cpp_template
    ! function_index=28
    function function8_double() result(rv)
        use iso_c_binding, only : C_DOUBLE
        implicit none
        real(C_DOUBLE) :: rv
        ! splicer begin function8_double
        rv = c_function8_double()
        ! splicer end function8_double
    end function function8_double
    
    ! void Function9(float arg+intent(in)+value)
    ! fortran_generic
    ! function_index=40
    subroutine function9_float(arg)
        use iso_c_binding, only : C_DOUBLE, C_FLOAT
        implicit none
        real(C_FLOAT), value, intent(IN) :: arg
        ! splicer begin function9_float
        call c_function9(real(arg, C_DOUBLE))
        ! splicer end function9_float
    end subroutine function9_float
    
    ! void Function9(double arg+intent(in)+value)
    ! fortran_generic
    ! function_index=41
    subroutine function9_double(arg)
        use iso_c_binding, only : C_DOUBLE
        implicit none
        real(C_DOUBLE), value, intent(IN) :: arg
        ! splicer begin function9_double
        call c_function9(arg)
        ! splicer end function9_double
    end subroutine function9_double
    
    ! void Function10()
    ! function_index=15
    subroutine function10_0()
        implicit none
        ! splicer begin function10_0
        call c_function10_0()
        ! splicer end function10_0
    end subroutine function10_0
    
    ! void Function10(const std::string & name+intent(in), float arg2+intent(in)+value)
    ! fortran_generic - string_to_buffer_and_len
    ! function_index=42
    subroutine function10_1_float(name, arg2)
        use iso_c_binding, only : C_INT, C_DOUBLE, C_FLOAT
        implicit none
        character(*), intent(IN) :: name
        real(C_FLOAT), value, intent(IN) :: arg2
        ! splicer begin function10_1_float
        call c_function10_1_bufferify(  &
            name,  &
            len_trim(name, kind=C_INT),  &
            real(arg2, C_DOUBLE))
        ! splicer end function10_1_float
    end subroutine function10_1_float
    
    ! void Function10(const std::string & name+intent(in), double arg2+intent(in)+value)
    ! fortran_generic - string_to_buffer_and_len
    ! function_index=43
    subroutine function10_1_double(name, arg2)
        use iso_c_binding, only : C_INT, C_DOUBLE
        implicit none
        character(*), intent(IN) :: name
        real(C_DOUBLE), value, intent(IN) :: arg2
        ! splicer begin function10_1_double
        call c_function10_1_bufferify(  &
            name,  &
            len_trim(name, kind=C_INT),  &
            arg2)
        ! splicer end function10_1_double
    end subroutine function10_1_double
    
    ! int overload1(int num+intent(in)+value)
    ! has_default_arg
    ! function_index=29
    function overload1_num(num) result(rv)
        use iso_c_binding, only : C_INT
        implicit none
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT) :: rv
        ! splicer begin overload1_num
        rv = c_overload1_num(num)
        ! splicer end overload1_num
    end function overload1_num
    
    ! int overload1(int num+intent(in)+value, int offset+default(0)+intent(in)+value)
    ! has_default_arg
    ! function_index=30
    function overload1_num_offset(num, offset) result(rv)
        use iso_c_binding, only : C_INT
        implicit none
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT), value, intent(IN) :: offset
        integer(C_INT) :: rv
        ! splicer begin overload1_num_offset
        rv = c_overload1_num_offset(  &
            num,  &
            offset)
        ! splicer end overload1_num_offset
    end function overload1_num_offset
    
    ! int overload1(int num+intent(in)+value, int offset+default(0)+intent(in)+value, int stride+default(1)+intent(in)+value)
    ! function_index=17
    function overload1_num_offset_stride(num, offset, stride) result(rv)
        use iso_c_binding, only : C_INT
        implicit none
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT), value, intent(IN) :: offset
        integer(C_INT), value, intent(IN) :: stride
        integer(C_INT) :: rv
        ! splicer begin overload1_num_offset_stride
        rv = c_overload1_num_offset_stride(  &
            num,  &
            offset,  &
            stride)
        ! splicer end overload1_num_offset_stride
    end function overload1_num_offset_stride
    
    ! int overload1(double type+intent(in)+value, int num+intent(in)+value)
    ! has_default_arg
    ! function_index=31
    function overload1_3(type, num) result(rv)
        use iso_c_binding, only : C_INT, C_DOUBLE
        implicit none
        real(C_DOUBLE), value, intent(IN) :: type
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT) :: rv
        ! splicer begin overload1_3
        rv = c_overload1_3(  &
            type,  &
            num)
        ! splicer end overload1_3
    end function overload1_3
    
    ! int overload1(double type+intent(in)+value, int num+intent(in)+value, int offset+default(0)+intent(in)+value)
    ! has_default_arg
    ! function_index=32
    function overload1_4(type, num, offset) result(rv)
        use iso_c_binding, only : C_INT, C_DOUBLE
        implicit none
        real(C_DOUBLE), value, intent(IN) :: type
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT), value, intent(IN) :: offset
        integer(C_INT) :: rv
        ! splicer begin overload1_4
        rv = c_overload1_4(  &
            type,  &
            num,  &
            offset)
        ! splicer end overload1_4
    end function overload1_4
    
    ! int overload1(double type+intent(in)+value, int num+intent(in)+value, int offset+default(0)+intent(in)+value, int stride+default(1)+intent(in)+value)
    ! function_index=18
    function overload1_5(type, num, offset, stride) result(rv)
        use iso_c_binding, only : C_INT, C_DOUBLE
        implicit none
        real(C_DOUBLE), value, intent(IN) :: type
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT), value, intent(IN) :: offset
        integer(C_INT), value, intent(IN) :: stride
        integer(C_INT) :: rv
        ! splicer begin overload1_5
        rv = c_overload1_5(  &
            type,  &
            num,  &
            offset,  &
            stride)
        ! splicer end overload1_5
    end function overload1_5
    
    ! void useclass(const Class1 * arg1+intent(in)+value)
    ! function_index=21
    subroutine useclass(arg1)
        implicit none
        type(class1), value, intent(IN) :: arg1
        ! splicer begin useclass
        call c_useclass(arg1%voidptr)
        ! splicer end useclass
    end subroutine useclass
    
    ! const string_result_fstr & LastFunctionCalled()+pure
    ! function_index=39
    function last_function_called() result(rv)
        use iso_c_binding, only : C_CHAR
        implicit none
        character(kind=C_CHAR, len=strlen_ptr(c_last_function_called())) :: rv
        ! splicer begin last_function_called
        rv = fstr(c_last_function_called())
        ! splicer end last_function_called
    end function last_function_called
    
    ! splicer begin additional_functions
    ! splicer end additional_functions
    
    function class1_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        implicit none
        type(class1), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%voidptr, b%voidptr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class1_eq
    
    function class1_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        implicit none
        type(class1), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%voidptr, b%voidptr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class1_ne
    
    ! Convert a null-terminated C "char *" pointer to a Fortran string.
    function fstr_ptr(s) result(fs)
      use, intrinsic :: iso_c_binding, only: c_char, c_ptr, c_f_pointer
      type(c_ptr), intent(in) :: s
      character(kind=c_char, len=strlen_ptr(s)) :: fs
      character(kind=c_char), pointer :: cptr(:)
      integer :: i
      call c_f_pointer(s, cptr, [len(fs)])
      do i=1, len(fs)
         fs(i:i) = cptr(i)
      enddo
    end function fstr_ptr
    
    ! Convert a null-terminated array of characters to a Fortran string.
    function fstr_arr(s) result(fs)
      use, intrinsic :: iso_c_binding, only : c_char, c_null_char
      character(kind=c_char, len=1), intent(in) :: s(*)
      character(kind=c_char, len=strlen_arr(s)) :: fs
      integer :: i
      do i = 1, len(fs)
         fs(i:i) = s(i)
      enddo
    end function fstr_arr
    
    ! Count the characters in a null-terminated array.
    pure function strlen_arr(s)
      use, intrinsic :: iso_c_binding, only : c_char, c_null_char
      character(kind=c_char, len=1), intent(in) :: s(*)
      integer :: i, strlen_arr
      i=1
      do
         if (s(i) == c_null_char) exit
         i = i+1
      enddo
      strlen_arr = i-1
    end function strlen_arr

end module tutorial_mod