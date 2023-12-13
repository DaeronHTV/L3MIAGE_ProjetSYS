#ifndef TimeModule
   #define TimeModule

   #include <stdio.h>
   #include "../Structure/StructTime.h"

   /**
    * Give the time into a char array object
    * @param time The time to convert into char array
    * @return The pointer of char array of the time
    * in the format HH:mm:ss
    * @author Avanzino A.
    * @since 06/12/2021
   **/
   char * ToString(Time time);

   /**
    * Give the time into a char array object with a
    * specified format 
    * @param time The time to convert into char array
    * @param format The format to use during the conversion
    * @author Avanzino A.
    * @since 06/12/2021
    **/
   char * ToString(Time time, char format);

   void addSeconds(Time * time, int seconds);

   void addMinutes(Time * time, int minutes);

   void addHours(Time * time, int hours);

   /**
    * Tell if two struct Temps are equals or not
    * @param t1 The first time to test
    * @param t2 the second time to test
    * @return 0 if the two objects aren't equals, 1 else
    * @author Avanzino A.
    * @since 06/12/2021
    **/
   int Equals(Time t1, Time t2);

   /**
    * 
    * @param t1 The first time
    * @param t2 The second time
    * @return A struct Time which represents the difference
    * between the two times
    * @author Avanzino A.
    * @since 06/12/2021
    **/
   Time * DiffTime(Time t1, Time t2);

   int DiffHours(Time t1, Time t2);

   int DiffMinutes(Time t1, Time t2);

   Time * Convert(char * chaine);

   Time * Convert(char * chaine, char format);

   int TryConvert(char * chaine, Time * result);

   int TryConvert(char * chaine, char format, Time * result);
#endif