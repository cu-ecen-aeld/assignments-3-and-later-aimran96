#https://stackoverflow.com/questions/6121091/how-to-extract-directory-path-from-file-path
VAR='/home/pax/file.c'
DIR="$(dirname "${VAR}")" ; FILE="$(basename "${VAR}")"
echo "[${DIR}] [${FILE}]"
