/* This program simulates an enrollment system.
It will receive a list with the registration of several students.
Initially it will receive an integer n indicating how many students will be received. 
Each student contains the following data, one per line:

Student Code (up to 30 characters);
student's full name (up to 500 characters);
age;
gender (0 for female, 1 for male);
vestibular result (grade) (0 to 10).
It will then receives an m number indicating the number of subjects to follow. Each subject has the
following format:

Course code (up to 25 characters);
subject name (up to 100 characters);
It will then receive a p number indicating a sequence of student enrollments in subjects. 
Each license plate will be given on one line, and each line contains 2 codes, separated by a blank space. 
The first code represents the student code and the second code the subject code and means that the student 
has applied for enrollment in that subject.

This program prints a report containing the following lines:

Number of male students;
Number of female students;
Average age of students, formatted to two decimal places;
Average age of students who scored higher than 7.5 in the vestibular result, formatted to two decimal places;
For each subject, ordered in alphabetical order,it prints the name of the subject, the number of students
enrolled in it and the names of the students who enrolled in it, also in alphabetical order, one per line. 
If there are no students enrolled, it simply does not print any students.

Sample Input:
4
AB100
Ambrosio Pai
38
1
8.3
0011
Ambrosina Maria
21
0
5
0002AB
Acacio da Silva
18
1
7.9
ABcd45
Maria Ambrosina
19
0
9
3
P1
Programacao 1
I1
Introducao a computacao
R1
Redes de computadores
5
AB100 P1
AB100 R1
ABcd45 P1
0002AB P1
0011 P1

Sample Output:
2
2
24.00
25.00
Introducao a computacao
0
Programacao 1
4
Acacio da Silva
Ambrosina Maria
Ambrosio Pai
Maria Ambrosina
Redes de computadores
1
Ambrosio Pai

*/
#include <stdio.h>
#include <string.h>
typedef struct {
	char codigo[35];
	char nome[505];
	int idade;
	int sexo;
	double nota;
}Cadastro;

typedef struct {
	char codmat[30];
	char nomemat[105];
	int quant;
	char matriculados[100][501];
}Materia;

int main(){
	int m, n, i,j,k, sequencia, homens=0, mulheres=0, ze=0, p;
	double media=0, mediaenem=0;
	Cadastro aluno[500];
	Materia discip[105];
	scanf("%d", &n);
	for (i=0;i<n;i++){
		scanf(" %s", aluno[i].codigo);
		scanf(" %502[^\n]", aluno[i].nome);
		scanf(" %d", &aluno[i].idade);
		scanf(" %d", &aluno[i].sexo);
		scanf(" %lf", &aluno[i].nota);
		if(aluno[i].nota>=7.5){
			mediaenem+=aluno[i].idade;
			ze++;
		}
		media+=aluno[i].idade;
		if(aluno[i].sexo==0){
			mulheres++;
		}else if(aluno[i].sexo==1){
			homens++;
		}
	}
	media = media/n*1.0;
	mediaenem = mediaenem/ze*1.0;
	scanf("%d", &m);
	for(i=0;i<m;i++){
		scanf(" %s",discip[i].codmat);
		scanf(" %102[^\n]",discip[i].nomemat);
		discip[i].quant=0;
	}

	scanf("%d", &p);
	for(i=0;i<p;i++){
		char ca[35], cm[30];
		scanf(" %s %s", ca,cm);
		for(j=0;j<n;j++){
			if(strcmp(ca,aluno[j].codigo)==0){
				for(k=0;k<m;k++){
					if(strcmp(cm,discip[k].codmat)==0){
						strcpy(discip[k].matriculados[discip[k].quant],aluno[j].nome);
						discip[k].quant++;
					}
				}
			}
		}
	}
	Materia aux;
	for(i=0;i<m-1;i++){
		for(j=i+1;j<m;j++){
			if(strcmp(discip[i].nomemat,discip[j].nomemat)>0){
				aux=discip[i];
				discip[i]=discip[j];
				discip[j]=aux;
			}
		}
	}
	char aux2[500];
	for(i=0;i<m;i++){
		for(j=0;j<discip[i].quant-1;j++){
			for(k=j+1;k<discip[i].quant;k++){
				if(strcmp(discip[i].matriculados[j],discip[i].matriculados[k])>0){
					strcpy(aux2,discip[i].matriculados[j]);
					strcpy(discip[i].matriculados[j],discip[i].matriculados[k]);
					strcpy(discip[i].matriculados[k],aux2);
				}
			}
		}
	}
	printf("%d\n",homens);
	printf("%d\n", mulheres);
	printf("%.2lf\n",media);
	printf("%.2lf\n",mediaenem);
	for(i=0;i<m;i++){
		printf("%s\n", discip[i].nomemat);
		printf("%d\n",discip[i].quant);
		if(discip[i].quant>0){
			for(k=0;k<discip[i].quant;k++){
				printf("%s\n",discip[i].matriculados[k]);
			}
		}
	}


	return 0;
}
