// This program is from: Chaz Carraway 
// The author believes it has <2> memory errors
// there is a segmentation fault and bus error. 


#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

  class Bad_mem{

  public:
   
      float height;
      float weight;
      float bmi;
      char *str1;
      char *str2;
      char *str3;
      char *str4;
      void bmiMeasure();
  };
   

  void Bad_mem :: bmiMeasure(){
     
     bmi = ((weight/(height*height))*703);
    
    if (bmi <= 18.0){
      strcpy(str2,"You are under weight, Eat more carbs");
      }

    else if ((18.0 <= bmi) && (bmi <= 18.5)){
      strcpy(str1,"You are thin for your height!");
      }

    else if ((18.6 <= bmi) && (bmi <= 24.9)){
    strcpy(str1,"Congrats you are not fat. You are at a healthy weight");     
     }

    else if ((25.0 <= bmi) && (bmi <= 29.9)){
      strcpy(str1,"You are overweight, you should lose some weight");
    }

    else{
      strcpy(str2,"Hate to say it but your fat, I would suggest stop eating entirely");
      }
   };



int main(){

  Bad_mem *stats;
  

  cout << "Enter your height in inches: " << endl;
  cin >> stats->height;

  if (stats->height <=0){
  cerr << "You height needs to be greater then zero!" << endl;
  exit(1);
  }
   
  cout << "Enter your weight in pounds: " << endl;
  cin >> stats->weight;

  if (stats->weight <=0){
  cerr << " Your weight needs to be greater then zero!" << endl;
  exit(1);
  }

  stats->bmiMeasure();
  free(stats.str1);
  free(stats.str2);
  printf("\nBased on your BMI number\n");
  memcpy(stats->str4,stats->str2,0);
  printf("\nstr4: %s\n", stats->str4);
  printf("str2: %s\n",stats->str2);
  memcpy(stats->str3,stats->str1,0); 
  printf("\nstr1: %s\n",stats->str1);
  printf("str3: %s\n", stats->str3); 
  printf("\nYour Height: %f\nYour Weight: %f\nYour BMI:    %f\n", stats->height, stats->weight, stats->bmi);
}
