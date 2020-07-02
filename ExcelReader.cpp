#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>

#define Max 10
#define COMP_STRING "Esta"
#define COL_SEP ','
#define FIL_SEP '\n'

using namespace std;

size_t split(char *string, char **fila, size_t maxvec);
int compare(char *str1, char *str2);

int
main(){
	ifstream ExcFile("./Test.csv",ifstream::binary);

	ExcFile.seekg(0, ExcFile.end);
	int length = ExcFile.tellg();
	ExcFile.seekg(0,ExcFile.beg);

	char * buff = new char [length];

	ExcFile.read(buff, length);

	printf("%s", buff);

	int pos;
	char * titles[Max];
	char * data = new char[Max];

	size_t dim = split(buff, titles, Max);
	//cout<<titles[0]<<endl;
	for (int i = 0; i < dim; i++)
	{
		cout<<titles[i]<<endl;
		//if(compare(titles[i], COMP_STRING)){
		//	pos = i;
		//}
	}
	//cout << "aca"<<endl;
	printf("%s", titles[pos]);
	
	return 0;
}

int compare(char *str1, char *str2){
	size_t i = 0;
	while(str1[i] != 0)
		if(str1[i] != str2[i])
			return 0;
	return 1;
}

size_t split(char *string, char **fila, size_t maxvec){
	size_t i = 0, beg = 0, f = 0;
	char ** aux = new char*[maxvec];
	while (string[i] != FIL_SEP )
	{
//		printf("%c %d\n", string[i], f);
		if((string[i] == COL_SEP) && (f < maxvec)){
			string[i] = 0;
//			cout << "if" << endl;
			strcpy(aux[f],string + beg);
			fila[f] = aux[f++];
			string[i] = COL_SEP;
			beg = i+1;
		}
		i++;
//		cout << "while"<<endl;
	}
	if(f < maxvec){
			string[i] = 0;
			strcpy(aux[f], string + beg);
			fila[f] = aux[f++];
			string[i] = FIL_SEP;
		}
//	cout << "Hoala"<<endl;
	return f;
}