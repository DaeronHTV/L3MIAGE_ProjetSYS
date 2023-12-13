#include "./Time.h"

char * ToString(Time time){
   char * result = (char*)malloc(sizeof(char)*8);
   sprintf(char temps[sizeof(char)*8], "%d:%d:%d", time.hours, time.minutes, time.secondes);
   return result; 
}

char * ToString(time time, char format){
   return NULL; //TODO
}

void addSeconds(time * time, int seconds){
   //time->secondes == (*time).secondes
   time->secondes += seconds;
}

void addMinutes(time * time, int minutes){
   time->minutes += minutes;
}

void addHours(time * time, int hours){
   time->hours += hours;
}

int Equals(Time t1, Time t2){
   if(&t1 == &t2){ return 1; }
   if(t1.secondes == t2.secondes){
      if(t1.minutes == t2.minutes){
         if(t1.hours == t2.hours){
            return 1;
         }
      }
   }
   return 0;
}

time * DiffTime(time t1, time t2){
   Time result;
   result.hours = t1.hours - t2.hours;
   result.minutes = t1.minutes - t2.minutes;
   result.secondes = t1.secondes = t2.secondes;
   if(result.secondes < 0){ 
      result.secondes += 60;
      result.minutes--; 
   }
   if(result.minutes < 0){
      result.minutes += 60;
      result.hours--;
   }
   if(result.hours < 0){ result.hours += 24; }
   return &result;
}

int DiffHours(time t1, time t2){
   return t1.hours - t2.hours < 0 ? t1.hours - t2.hours + 60 : t1.hours - t2.hours;
}

int DiffMinutes(time t1, time t2){
   return t1.minutes - t2.minutes < 0 ? 
   t1.minutes - t2.minutes + 60 : t1.minutes - t2.minutes;
}

time * Convert(char * chaine){
   time result;
   char * token;
   token = strtok(chaine, ":");
   time.hours = atoi(token);
   token = strtok(NULL, ":");
   time.minutes = atoi(token);
   return &time;
}