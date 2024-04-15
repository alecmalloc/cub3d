#ifndef ERROR_CUB_H
# define ERROR_CUB_H

//define ErrorCodes

//MLX init error
# define MLX_INIT_ERR 91

# define MLX_IMG_ERR 92

//Faulty line error
# define WRL_ERR 95

//Wrong Argument
# define WRA_ERR 96

//malloc error
# define MALL_ERR 97 

//Wrong Suffix error
# define WRS_ERR 98

//Open File error
# define OPF_ERR 99

// double path
# define DNP_ERR 100
# define DEP_ERR 101
# define DSP_ERR 102
# define DWP_ERR 103

//Path Unaccsessible
# define NPU_ERR 110
# define EPU_ERR 111
# define SPU_ERR 112
# define WPU_ERR 113

//Path missing
# define NPM_ERR 120
# define EPM_ERR 121
# define SPM_ERR 122
# define WPM_ERR 123

//Path Wrong Format
# define NPW_ERR 130
# define EPW_ERR 131
# define SPW_ERR 132
# define WPW_ERR 133

//RGB Number missing
# define MFN_ERR 140
# define MCN_ERR 141

//double Rgb Number
# define DFN_ERR 150
# define DCN_ERR 151

//RGB Number Wrong
# define WFN_ERR 160
# define WCN_ERR 161

//RGB wrong format
# define WFF_ERR 170
# define WFC_ERR 171

//Path Wrong Suffix
# define WSN_ERR 180
# define WSE_ERR 181
# define WSS_ERR 182
# define WSW_ERR 183

//Map not found
# define MNF_ERR 200

//Wrong Char in Map
# define WCM_ERR 201

//Double player
# define DPL_ERR 202

//Open Wall
# define OPW_ERR 203

# define DIRECTIONS {"North", "East", "South", "West"}
# define BOTOP {"Floor", "Ceiling"} 

void	print_single(int err);
void	print_doublep(int err);
void	print_unaccesp(int err);
void	print_missingp(int err);
void	print_wrongp(int err);
void	print_missingn(int err);
void	print_doublen(int err);
void	print_wrongn(int err);
void	print_wrongfn(int err);
void	print_wrongsf(int err);

#endif
