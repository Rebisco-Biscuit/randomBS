/* From Exercism, Leap */

bool leap_year(int year){
    if((year%4==0 && year%100!=0) || (year%100==0 && year%400==0 && year%4==0)){
        return true;
    } else {
        return false;
    }
}
