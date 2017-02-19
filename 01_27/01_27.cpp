#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <fstream>
#include <cctype>

typedef std::list<std::pair<size_t, std::string>> TopList;

void TrimPuncts(std::string& word)
{
    /*we need to check only the first and last characters 
      to avoid splicing the words with hyphen*/
    if(std::ispunct(word[0]) ||
       std::isdigit(word[0]))
    {
        word.erase(0, 1);
    }

    if(std::ispunct(word[word.size() - 1]) ||
       std::isdigit(word[word.size() - 1]))
    {
        word.erase(word.size() - 1, word.size());
    }

    word.shrink_to_fit();
}

TopList MakeTopOfWords(const std::string& path_to_file, size_t top, bool case_sensitive,
                       const std::list<std::string> excludes)
{
    std::fstream f;
    f.open(path_to_file);
    if(!f.is_open())
    {
        throw std::ios_base::failure("File is not opened");
    }

    char letter;
    std::string word;
    std::unordered_map<std::string, size_t> word_sheet;

    while (!f.eof())
    {
        f.get(letter);
        if(std::isgraph(letter))
        {
            word.push_back(letter);
        }
        else if(std::isspace(letter))
        {
            if(!word.empty())
            {
                //Θ(n)
                TrimPuncts(word);

                std::string tmp_word = word;
                std::transform(tmp_word.begin(), tmp_word.end(), tmp_word.begin(), ::tolower);

                if(std::any_of(excludes.begin(),
                               excludes.end(),
                               [tmp_word](const std::string& s){ return tmp_word == s; }))
                {
                    word.clear();
                    continue;
                }

                if(!case_sensitive)
                {
                    word = tmp_word;
                }

                auto it = word_sheet.find(word);
                if(it == word_sheet.end())
                {
                    word_sheet.insert(std::make_pair(word, 1));
                }
                else
                {
                    it->second++;
                }
                word.clear();
            }
        }
    }

    f.close();

    TopList full;
    for (auto it = word_sheet.begin(); it != word_sheet.end(); ++it)
    {
        full.push_back(std::make_pair(it->second, it->first));
    }

    //Θ(log(n))
    full.sort(std::greater<std::pair<size_t, std::string>>());

    top = std::min(top, full.size());

    TopList out;
    for(auto it = full.begin(); top; --top, ++it)
    {
        out.push_back(*it);
    }

    return out;
}

int main()
{
    std::list<std::string> excludes =
    {
        "which", "were", "on", "at", "i", "or", "and", "that", "this",
        "with", "thy", "thou", "o", "the", "of", "not", "is", "a", "to",
        "as", "in", "for", "me", "his", "her", "he", "him", "what",
        "she", "all", "so", "by", "thee", "will", "have", "been", "my",
        "be", "shall", "but", "from", "your", "do", "it", "are", "an",
        "their", "did", "they", "was", "had", "who", "its", "into", "has",
        "any", "would", "them"
    };

    std::string path = "/home/vadym/Desktop/28054-0.txt";

    TopList tl = MakeTopOfWords(path, 10, true, excludes);

    for(auto i : tl)
    {
        std::cout << i.first << " : " << i.second << std::endl;
    }

    return 0;
}
