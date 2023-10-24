VAR='/home/pax/file.c'
DIR="$(dirname "${VAR}")" ; FILE="$(basename "${VAR}")"
echo "[${DIR}] [${FILE}]"
