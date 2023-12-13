#ifndef DateModule
   #define DateModule

   #include "../Structure/StructTime.h"

   /**
    * Give the time into a char array object
    * @param date The time to convert into char array
    * @return The pointer of char array of the time
    * in the format HH:mm:ss
    * @author Avanzino A.
    * @since 06/12/2021
   **/
   char * ToString(Date date);

   /**
    * Give the time into a char array object with a
    * specified format 
    * @param date The time to convert into char array
    * @param format The format to use during the conversion
    * @author Avanzino A.
    * @since 06/12/2021
    **/
   char * ToString(Date date, char format);

   void addSeconds(Date * date, int seconds);

   void addMinutes(Date * date, int minutes);

   void addHours(Date * date, int hours);

   /**
    * Tell if two struct Date are equals or not
    * @param d1 The first date to test
    * @param d2 the second date to test
    * @return 0 if the two objects aren't equals, 1 else
    * @author Avanzino A.
    * @since 06/12/2021
    **/
   int Equals(Date d1, Date d2);

   /**
    * 
    * @param d1 The first date
    * @param d2 The second date
    * @return A struct Date which represents the difference
    * between the two dates
    * @author Avanzino A.
    * @since 06/12/2021
    **/
   Date * DiffDate(Date d1, Date d2);

   int DiffMonth(Date d1, Date d2);

   int DiffYear(Date d1, Date d2);

   int DiffDay(Date d1, Date d2);

   Date * Convert(char * chaine);

   Date * Convert(char * chaine, char format);

   int TryConvert(char * chaine, Date * result);

   int TryConvert(char * chaine, char format, Date * result);
#endif