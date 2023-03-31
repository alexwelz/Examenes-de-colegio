
/*
Un colegio desea conocer el nivel de conocimientos de sus alumnos y para ello
prepara exámenes de 12 materias para todos sus alumnos. El colegio cuenta con un
total de 500 alumnos pero no necesariamente todos ellos rindieron todos los
exámenes.
Los registros se encuentran agrupados por legajo del alumno. Para finalizar la carga
de datos de una materia se ingresa un legajo de alumno negativo.
Cada examen rendido por alumno de una materia se registra de la siguiente manera:

- Código de materia (entero)
- Legajo de alumno (entero) (1000 a 2500)
- Modalidad (carácter) ('P' - Presencial, 'V' - Virtual)
- Duración (entero) (en minutos)
- Nota (float)

Aclaraciones:
- Todos los exámenes, indistintamente de la materia, se aprueban con nota >=
6.
Se pide calcular e informar:
A) Por cada materia, el promedio de duración de los exámenes que hayan sido
aprobados.

B) El porcentaje de exámenes presenciales y de exámenes virtuales rendidos por el alumno con legajo 1100.

C) La cantidad de materias que jamás hayan tomado exámenes virtuales.

D) Los códigos de materia de los dos exámenes presenciales más largos.

NOTA: Habrá al menos dos exámenes presenciales.

E) La modalidad (Virtual o Presencial) que más exámenes desaprobados haya
registrado en total.

*/

#include <iostream>
using namespace std;
#include <cstdlib>

int main (void){
setlocale(LC_ALL, "Spanish");


    const int MATERIAS=12;

    int cod_materia,legajo_alumno, duracion;
    char modalidad;
    float nota;

    //B
    int presen=0,virtu=0, totexamen;
    //C
    bool NOvirtual=false;
    int contVirtual=0;
    //E
    int contDesapV=0, contDesapP=0;
    //D
    int maxi1, maxi2, cod_mat1, cod_mat2;
    bool b_max=false;





    for(int x=0; x<MATERIAS; x++)
   {

        cout<<endl<<"Ingrese legajo alumno"<<endl;
        cin>>legajo_alumno;

       //A
       int acumdurac=0;
       int durac=0;

        while(legajo_alumno>= 0)
        {
           cout<<endl<<"Ingrese la materia "<<endl;
            cin>>cod_materia;
           cout<<endl<<"Ingrese modalidad "<<endl;
           cin>>modalidad;
           cout<<endl<<"Ingrese duracion "<<endl;
           cin>>duracion;
           cout<<endl<<"Ingrese nota "<<endl;
           cin>>nota;

            //E
            if(modalidad=='V' && nota < 6)
            {
                contDesapV++;
            }
            else
            {
               if(modalidad=='P' && nota < 6)
                {
                    contDesapP++;
                }
            }

           //A
           if(nota>=6)
           {
               acumdurac += duracion;
               durac++;
           }


           //B
           if(legajo_alumno== 1100)
           {
               switch(modalidad)
               {
               case 'P':
                   presen++;
                   break;
               case 'V':
                    virtu++;
                    break;


               }
           }

           //C
           if(modalidad == 'V')
           {
               NOvirtual =true;
           }


           //D
           ///1er Vuelta
           if(b_max==true)
           {
                if(modalidad =='P')
                {
                    maxi2=duracion;
                    maxi1= duracion;

                    cod_mat2 = cod_materia;
                    cod_mat1 = cod_materia;
                    b_max = false;
                }
           }
           ///2da Vuelta
            if(duracion > maxi1)
            {
                maxi2= maxi1;
                maxi1= duracion;

                cod_mat2= cod_mat1;
                cod_mat1= cod_materia;
            }
            else
            {
                if(duracion > maxi2)
                {
                    maxi2= duracion;
                    cod_mat2= cod_materia;

                }

            }

            cout<<endl<<"Ingrese legajo alumno"<<endl;
            cin>>legajo_alumno;


       }


       //C
       if(NOvirtual==false)
       {
           contVirtual++;
       }
       NOvirtual=false;

       cout<<endl<<"-------------------------------"<<endl;
       cout<<endl<<"PUNTO  A"<<endl;
       if(acumdurac>0)
       {
            cout<<endl<<" El alumno tiene un promedio de duracion de examenes aprobados de " <<acumdurac/durac<<endl;

       }
       else
       {
           cout<<endl<<"No tuvo materias aprobadas"<<endl;
       }




   }

    cout<<endl<<"-------------------------------"<<endl;
    cout<<endl<<"PUNTO  B"<<endl;
    totexamen = presen +virtu;
    cout<<endl<< "Presenciales: "<< (presen*100)/totexamen<<" %"<<endl;
    cout<<endl<< "Virtuales: "<< (virtu*100)/totexamen<<" %"<<endl;

    cout<<endl<<"-------------------------------"<<endl;
    cout<<endl<<"PUNTO  C"<<endl;
    cout<<endl<< "La cantidad de materias que no tomaron examenes virtuales son "<<contVirtual<<endl;
    cout<<endl<<"-------------------------------"<<endl;
    cout<<endl<<"PUNTO  E"<<endl;
    if(contDesapV > contDesapP)
    {
        cout<<endl<<"La modalidad que mas examenes deaprobados registro fue Virtual"<<endl;
    }
    else
    {
        cout<<endl<<"La modalidad que mas examenes deaprobados registro fue Presencial"<<endl;
    }
    cout<<endl<<"-------------------------------"<<endl;
    cout<<endl<<"PUNTO  D"<<endl;
    cout<<endl<< "Los cod materias presenciales mas largos fueron  "<<cod_mat1 <<" y el siguiente " <<cod_mat2<<endl;




return 0;
}
