#ifndef ERROR_CUB_H
# define ERROR_CUB_H

//define ErrorCodes

//malloc error
# define MALL_ERR 97 

//Wrong Suffix error
# define WRS_ERR 98

//Open File error
# define OPF_ERR 99

//Faulty line error
# define WRL_ERR 100

// double path
# define DNP_ERR 101
# define DWP_ERR 102
# define DEP_ERR 103
# define DSP_ERR 104

//Path Unaccsessible
# define NPU_ERR 105
# define EPU_ERR 106
# define WPU_ERR 107
# define SPU_ERR 108

//RGB Number Floor
# define DFN_ERR 109
# define MFN_ERR 110
# define WFN_ERR 111


//RGB Number Celing
# define DSN_ERR 109
# define MSN_ERR 110
# define WSN_ERR 111

int	print_error(int err_code);

#endif
