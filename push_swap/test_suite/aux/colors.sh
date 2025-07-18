#!/bin/bash

# Reset and Styles
RST="\033[0m"  # Reset - Réinitialise le style au défaut
BLD="\033[1m"  # Bold - Texte en gras
DIM="\033[2m"  # Dim - Texte plus clair
ITL="\033[3m"  # Italic - Texte en italique (non toujours supporté)
UND="\033[4m"  # Underline - Texte souligné
BLI="\033[5m"  # Blink - Texte clignotant
INV="\033[7m"  # Invert - Inverse les couleurs

# standard et intense
BRBK="\033[90m" BRBK_B="\033[1;90m"
BRRD="\033[91m" BRRD_B="\033[1;91m"
BRGN="\033[92m" BRGN_B="\033[1;92m"
BRYL="\033[93m" BRYL_B="\033[1;93m"
BRBL="\033[94m" BRBL_B="\033[1;94m"
BRMG="\033[95m" BRMG_B="\033[1;95m"
BRCN="\033[96m" BRCN_B="\033[1;96m"
BRWT="\033[97m" BRWT_B="\033[1;97m"

# Colors - Normal, Bold, Dim, Underlined, Blink
BK="\033[30m"  BK_B="\033[1;30m"  BK_D="\033[2;30m"  BK_U="\033[4;30m"  BK_BL="\033[5;30m"
RD="\033[31m"  RD_B="\033[1;31m"  RD_D="\033[2;31m"  RD_U="\033[4;31m"  RD_BL="\033[5;31m"
GN="\033[32m"  GN_B="\033[1;32m"  GN_D="\033[2;32m"  GN_U="\033[4;32m"  GN_BL="\033[5;32m"
YL="\033[33m"  YL_B="\033[1;33m"  YL_D="\033[2;33m"  YL_U="\033[4;33m"  YL_BL="\033[5;33m"
BL="\033[34m"  BL_B="\033[1;34m"  BL_D="\033[2;34m"  BL_U="\033[4;34m"  BL_BL="\033[5;34m"
MG="\033[35m"  MG_B="\033[1;35m"  MG_D="\033[2;35m"  MG_U="\033[4;35m"  MG_BL="\033[5;35m"
CN="\033[36m"  CN_B="\033[1;36m"  CN_D="\033[2;36m"  CN_U="\033[4;36m"  CN_BL="\033[5;36m"
WT="\033[37m"  WT_B="\033[1;37m"  WT_D="\033[2;37m"  WT_U="\033[4;37m"  WT_BL="\033[5;37m"

# Background Colors
BG_BK="\033[40m"  # Black
BG_RD="\033[41m"  # RD_B
BG_GN="\033[42m"  # Green
BG_YL="\033[43m"  # YL_Blow
BG_BL="\033[44m"  # BL_Be
BG_MG="\033[45m"  # MG_Benta
BG_CN="\033[46m"  # CN_Bn
BG_WT="\033[47m"  # White
