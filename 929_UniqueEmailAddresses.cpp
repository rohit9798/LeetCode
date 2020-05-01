Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 

 

Example 1:

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
 

Note:

1 <= emails[i].length <= 100
1 <= emails.length <= 100
Each emails[i] contains exactly one '@' character.
All local and domain names are non-empty.
Local names do not start with a '+' character.




class Solution {
public:
    vector<string> split(string email)
    {
        int flag = 0, i = 0, flag1 = 0;
        vector<string> result;
        string temp = "", temp2 = "";
        while(email[i] != '\0')
        {
            if(email[i] == '@')
                flag = 1;
            else if(flag == 0)
                temp = temp + email[i];
            else
                temp2 = temp2 + email[i];
            i++;
        }
        result.push_back(temp);
        result.push_back(temp2);
        return result;
    }
    int numUniqueEmails(vector<string>& emails) {
        
        if(emails.size() == 0)
            return 0;
        map<pair<string, string>, int> m;
        string temp = "";
        for(int i = 0; i < emails.size(); i++)
        {
            vector<string> splitStr = split(emails[i]);
            temp = "";
            for(int i = 0; i < splitStr[0].length(); i++)
            {
                if(splitStr[0][i] == '.')
                    continue;
                else if(splitStr[0][i] == '+')
                    break;
                else
                    temp = temp + splitStr[0][i];
                    
            }
            if(m[{temp, splitStr[1]}] > 0 )
            {       
                m[{temp, splitStr[1]}]++;
            }
        }
        return m.size();
    }
};
