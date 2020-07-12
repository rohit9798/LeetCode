Given a date string in the form Day Month Year, where:

Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
Year is in the range [1900, 2100].
Convert the date string to the format YYYY-MM-DD, where:

YYYY denotes the 4 digit year.
MM denotes the 2 digit month.
DD denotes the 2 digit day.
 

Example 1:

Input: date = "20th Oct 2052"
Output: "2052-10-20"
Example 2:

Input: date = "6th Jun 1933"
Output: "1933-06-06"
Example 3:

Input: date = "26th May 1960"
Output: "1960-05-26"



class Solution {
public:
    string reformatDate(string date) {
        
        int i = 0;
        string dd, mm, yy;
        map<string, string> m;
        m["Jan"] = "01";
        m["Feb"] = "02";
        m["Mar"] = "03";
        m["Apr"] = "04";
        m["May"] = "05";
        m["Jun"] = "06";
        m["Jul"] = "07";
        m["Aug"] = "08";
        m["Sep"] = "09";
        m["Oct"] = "10";
        m["Nov"] = "11";
        m["Dec"] = "12";
        for(int j = 0; j < 3; j++)
        {
            string temp = "";
            while(i < date.length() && date[i] != ' ')
            {
                if(j == 0)
                {
                    if(isdigit(date[i]))
                        temp = temp + date[i];
                    dd = temp;
                }
                else
                {
                    temp = temp + date[i];
                }
                i++;
            }
            if(j == 1)
                mm = m[temp];
            else if(j == 2)
                yy = temp;
            i++;
        }
        if(dd.length() == 1)
            dd = "0" + dd;
        string result = yy + "-" + mm + "-"+ dd;
        return result;
    }
};
