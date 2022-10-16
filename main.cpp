#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <string.h>
#include <typeinfo>

using namespace std;

 int main()
{
    ifstream inputfilename("E:\\input.txt");
    ofstream outputfilename("E:\\output.txt");
    string temp, keyword_t, found_keywords,stringg,Shafin;

    int i, keywords_count=0, check_a=0;

    string keyword32[] = {"auto", "double",	"int",	"struct", "break",	"else",	"long",	"switch", "case",	"enum",	"register",
    "typedef","char",	"extern",	"return",	"union", "const",	"float",	"short",	"unsigned", "continue",	"for",
    "signed", "void","default",	"goto",	"sizeof",	"volatile", "do",	"if",	"static",	"while"} ;

    string datatype[] = {"int", "float", "double", "char", "bool", "String" };

    bool check;
    if(inputfilename.is_open())
    {
        while (getline(inputfilename,temp))
        {

        // Comments Remove
            for (i=0; i<temp.length();i++)
            {
                if (temp[i]=='/' &&temp[i+1]=='/')
                {
                    break;
                }
                if(temp[i]=='/' &&temp[i+1]=='*')
                {
                    check = true;
                }
                if(temp[i]=='*' &&temp[i+1]=='/')
                {
                    check = false;
                    i= i+2;
                }
                if (check==false)
                    outputfilename<<temp[i];
            }
            outputfilename<<"\n";


        // Keyword
            for (i=0; i<temp.length();i++)
            {
                if(temp[i] !=' ' )
                {
                    keyword_t = keyword_t + temp[i];
                }

                else
                {
                    for(int i=0;i<32;i++)
                    {
                        if(keyword32[i] == keyword_t)
                        {
                            cout<<keyword32[i]<<endl;
                            found_keywords.append(keyword32[i] + "\n");
                            keywords_count++;

                        }
                    }
                    keyword_t="";
                }
            }

            // Variable
            keyword_t="";
            for (int i=0; i<temp.length();i++)
            {

                if(temp[i] !=' ' )
                {
                    keyword_t = keyword_t + temp[i];
                }
                else
                {
                    for(int x=0;x<6;x++)
                    {
                        if(datatype[x] == keyword_t)
                        {
                            stringg="";
                            for(int y=i+1; y<temp.length()-1; y++ )
                            {
                                stringg += temp[y];
                            }
                        }
                    }
                    keyword_t="";
                }
            }

            // Symbol
            for (int i=0; i<temp.length();i++)
            {
                if(temp[i] == '#')
                {
                    Shafin+="# - Hash.\n";
                }
                if(temp[i] == '<')
                {
                    Shafin+="< - Less Than.\n";
                }
                if(temp[i] == '.')
                {
                    Shafin+=". - Dot.\n";
                }
                if(temp[i] == '>')
                {
                    Shafin+="> - Greater Than.\n";
                }
                if(temp[i] == ';')
                {
                    Shafin+="; - Semi-clone.\n";
                }
                if(temp[i] == ',')
                {
                    Shafin+=", - Comma.\n";
                }
                if(temp[i] == '+')
                {
                    Shafin+="+ - Plus.\n";
                }
                if(temp[i] == '-')
                {
                    Shafin+="- - Minus.\n";
                }
                if(temp[i] == '*')
                {
                    Shafin+="* - Asterisk.\n";
                }
                if(temp[i] == '/')
                {
                    Shafin+="/ - ForwardSlash.\n";
                }
                if(temp[i] == '=')
                {
                    Shafin+="= - Equal.\n";
                }
                if(temp[i] == '(')
                {
                    Shafin+="( - Left Parenthesis.\n";
                }
                if(temp[i] == ')')
                {
                    Shafin+=") - Right Parenthesis.\n";
                }
                if(temp[i] == '[')
                {
                    Shafin+="[ - Left Square Bracket.\n";
                }
                if(temp[i] == ']')
                {
                    Shafin+="] - Right Square Bracket.\n";
                }
                if(temp[i] == '{')
                {
                    Shafin+="{ - Left Curly Bracket.\n";
                }
                if(temp[i] == '}')
                {
                    Shafin+="} - Right Curly Bracket.\n";
                }

            }

        }

    }

    outputfilename<<"\nKeywords:";
    outputfilename << "\n" << found_keywords;
    outputfilename<<"\nVariables: \n";
    outputfilename<<stringg;
    outputfilename<<"\n\nSymbol:"<<endl;
    outputfilename<<Shafin;

    return 0;
}

