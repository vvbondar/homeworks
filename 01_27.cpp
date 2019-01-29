#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <list>
#include <functional>

using namespace std;

list<pair<size_t, string>> MakeTopOfWords(const string& path, size_t top, bool case_sensitive)
{
    ifstream f;
    f.open(path);

    char letter;
    string word;
    unordered_map<string, size_t> words_list;

    static list<string> banned_words =
    {
        "which", "were", "on", "at", "i", "or", "and", "that", "this",
        "with", "thy", "thou", "o", "the", "of", "not", "is", "a", "to",
        "as", "in", "for", "me", "his", "her", "he",  "him", "what",
        "she", "all", "so", "by", "thee", "will", "have", "been", "my",
        "be", "shall", "but", "from", "your", "do", "it"
    };

    // lock check

    static list<char> banned_chars =
    {
        ' ', '\n', ',', '.', '!', '-', '|', '?',
         ';', ':', '(', ')', '[', ']', '{', '}',
        '\"', '\"'
    };

    while(!f.eof())
    {
        f.get(letter);

        //Θ(n)
        if(all_of(banned_chars.begin(),
                  banned_chars.end(),
                  [letter](const char c){ return letter != c; }))
        {
            //Θ(n)
            word.push_back(letter);
        }
        else
        {
            if(word[0] == '\'')
            {
                //Θ(1)
                word.erase(0);
            }

            if(!word.empty())
            {
                string t_word = word;
                
                transform(t_word.begin(), t_word.end(), t_word.begin(), ::tolower);

                //Θ(n)
                if(all_of(banned_words.begin(),
                          banned_words.end(),
                          [t_word](const string& str){ return str != t_word; }))
                {
                    //Θ(1)
                    auto it = words_list.find(word);
                    if(it == words_list.end())
                    {
                        //Θ(1)
                        words_list.insert(pair<string, size_t>(word, 1));
                    }
                    else
                    {
                        it->second++;
                    }
                }
                word.clear();
            }
        }
    }

    f.close();

    //One comparison
    top = min(top, words_list.size());

    list<pair<size_t, string>> temp_storage;

    for(auto it = words_list.begin(); it != words_list.end(); ++it)
    {
        //Θ(1)
        temp_storage.push_back(make_pair(it->second, it->first));
    }

    /*
    Θ(n*log(n))

    Got a wierd underline below the 'sort' (Too many arguments),
    but everything works fine (kinda)
    */
    temp_storage.sort(greater<pair<size_t, string>>());

    list<pair<size_t, string>> out;

    for (auto it = temp_storage.begin(); top; --top, ++it)
    {
        //Θ(1)
        out.push_back(*it);
    }

    return out;
}

int main()
{
    string path = "C:\\users\\vikec\\Desktop\\text.txt";
    auto sheet = MakeTopOfWords(path, 10, false);

    for(auto it = sheet.begin(); it != sheet.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}
