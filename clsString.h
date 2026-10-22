#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class clsString
{
private:
    string _Value;

public:
    clsString()
    {
    }

    clsString(string _Value)
    {
        this->_Value = _Value;
    }

    void Set_Value(string Value)
    {
        _Value = Value;
    }

    string Get_Value()
    {
        return _Value;
    }

    // __declspec(property(get = Get_Value, put = Set_Value))string Value;

    static short Count_Words(string s)
    {
        string Delim = " ";
        short Count_word = 0;
        short pos = 0;

        cout << " the Words is : ";
        string esWord;

        while ((pos = s.find(Delim)) != std::string::npos)
        {
            esWord = s.substr(0, pos);
            if (esWord != "")
            {
                Count_word++;
            }

            s.erase(0, pos + Delim.length());
        }
        if (s != "")
            Count_word++;

        return Count_word;
    }

    short Count_Words()
    {
        return Count_Words(_Value);
    }

    static short Length(string s)
    {
        return s.length();
    }

    short Length()
    {
        return _Value.length();
    }

    static string Upper_First_letter_Of_Each_Word(string s)
    {
        bool is_First_letter = true;

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] != ' ' && is_First_letter == true)
                s[i] = toupper(s[i]);

            is_First_letter = (s[i] == ' ' ? true : false);
        }

        return s;
    }
    void Upper_First_letter_Of_Each_Word()
    {
        _Value = Upper_First_letter_Of_Each_Word(_Value);
    }

    static string LOWER_First_letter_Of_Each_Word(string s)
    {
        bool is_First_letter = true;

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] != ' ' && is_First_letter == true)
                s[i] = tolower(s[i]);

            is_First_letter = (s[i] == ' ' ? true : false);
        }

        return s;
    }
    void LOWER_First_letter_Of_Each_Word()
    {
        _Value = LOWER_First_letter_Of_Each_Word(_Value);
    }

    static string LOWER_All_letter(string s)
    {

        for (int i = 0; i < s.length(); i++)
        {

            s[i] = tolower(s[i]);
        }

        return s;
    }
    void LOWER_All_letter()
    {
        _Value = LOWER_All_letter(_Value);
    }

    static string UpperAllString(string s)
    {

        for (int i = 0; i < s.length(); i++)
        {

            s[i] = toupper(s[i]);
        }

        return s;
    }
    void UPPER_All_letter()
    {
        _Value = UpperAllString(_Value);
    }

    static char invert_Letter_Case(char c)
    {
        return isupper(c) ? tolower(c) : toupper(c);
    }

    static string invert_All_letter_Case(string s)
    {

        for (int i = 0; i < s.length(); i++)
        {

            s[i] = invert_Letter_Case(s[i]);
        }

        return s;
    }
    void invert_All_letter_Case()
    {
        _Value = invert_All_letter_Case(_Value);
    }

    enum enWhat_To_Count
    {
        Small_letter = 1,
        Capital_letter = 2,
        All = 3
    };

    static short Count_Letters(string s, enWhat_To_Count What_To_Count = enWhat_To_Count::All)
    {
        if (What_To_Count == enWhat_To_Count::All)
        {
            return s.length();
        }

        short Count_letter = 0;

        for (short i = 0; i < s.length(); i++)
        {
            if (What_To_Count == enWhat_To_Count::Capital_letter && isupper(s[i]))
                Count_letter++;

            if (What_To_Count == enWhat_To_Count::Small_letter && islower(s[i]))
                Count_letter++;
        }

        return Count_letter;
    }

    static short Count_capital_letter(string s)
    {
        short Count_capital_letter = 0;

        for (short i = 0; i < s.length(); i++)
        {
            (isupper(s[i]) ? Count_capital_letter++ : false);
        }

        return Count_capital_letter;
    }
    short Count_capital_letter()
    {
        return Count_capital_letter(_Value);
    }

    static short Count_Small_letter(string s)
    {
        short Count_Small_letter = 0;

        for (short i = 0; i < s.length(); i++)
        {
            (islower(s[i]) ? Count_Small_letter++ : false);
        }

        return Count_Small_letter;
    }
    short Count_Small_letter()
    {
        return Count_Small_letter(_Value);
    }

    static short Count_Specific_letter(string s, char letter, bool MathCase = true)
    {
        short Count_letter = 0;

        for (short i = 0; i < s.length(); i++)
        {
            if (MathCase)
            {
                if (s[i] == letter)
                    Count_letter++;
            }

            else
            {
                if (tolower(s[i]) == tolower(letter))
                    Count_letter++;
            }
        }

        return Count_letter;
    }
    short Count_Specific_letter(char letter, bool MathCase = true)
    {
        return Count_Specific_letter(_Value, letter, MathCase);
    }

    static bool The_letter_is_Vowel(char C)
    {
        char CC = tolower(C);
        return (CC == 'a') || (CC == 'e') || (CC == 'i') || (CC == 'o') || (CC == 'u');
    }
    static short Count_The_letter_Vowel(string s)
    {
        short Count_letter = 0;

        for (short i = 0; i < s.length(); i++)
        {
            if (The_letter_is_Vowel(s[i]))
                Count_letter++;
        }

        return Count_letter;
    }
    short Count_The_letter_Vowel()
    {
        return Count_The_letter_Vowel(_Value);
    }

    static vector<string> Split(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable

        // use find() function to get the position of the delimiters
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word
            // if (sWord != "")
            // {
            vString.push_back(sWord);
            //}

            S1.erase(0, pos + Delim.length()); /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;
    }
    vector<string> split(string Delim)
    {
        return Split(_Value, Delim);
    }

    static void Print_each_String_in_word(string s)
    {
        string empty = " ";

        short pos = 0;

        string word = " ";

        while ((pos = s.find(empty)) != std::string::npos)
        {
            word = s.substr(0, pos);

            if (word != " ")
            {
                cout << word << endl;
            }
            s.erase(0, pos + empty.length());
        }
        if (s != " ")

            cout << s << endl;
    }

    void Print_each_String_in_word()
    {
        Print_each_String_in_word(_Value);
    }

    void Print_vector_string(vector<string> vString)
    {
        for (string &vstring : vString)
        {
            cout << vstring << endl
                 << endl;
        }
    }

    string Trim_lift(string s)
    {

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                return s.substr(i, s.length() - 1);
            }
        }
        return "";
    }

    string Trim_rigth(string s)
    {

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                return s.substr(0, i + 1);
            }
        }
        return "";
    }

    string Print_string_Two_aWay(string s)
    {
        return Trim_lift(Trim_rigth(s));
    }

    static string reversing_words(string String)

    {
        vector<string> vString = Split(String, " ");

        string SS;

        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {
            --iter;
            SS += *iter + " ";
        }

        return SS.substr(0, SS.length() - 1);
    }
    string reversing_words()
    {
        return reversing_words(_Value);
    }

    string Join_string(vector<string> vString, string Delim)
    {
        string SS;

        for (string &S : vString)
        {
            SS += S + Delim;
        }

        return SS.substr(0, SS.length() - Delim.length());
    }
    string Join_string(string arr_String[], short Length, string Delim)
    {
        string SS;

        for (short i = 0; i < Length; i++)
        {

            SS += arr_String[i] + Delim;
        }

        return SS.substr(0, SS.length() - Delim.length());
    }
};
