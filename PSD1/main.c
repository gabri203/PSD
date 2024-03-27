int main (int argc, char * argv[]){
FILE *fp_input;

if((fp_input=fopen(argv[1], "r")) == NULL) {
fprintf(stderr, "Errore apertura file di INPUT %s\n", argv[1]);
exit (EXIT_FAILURE);
}