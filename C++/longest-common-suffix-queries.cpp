class Trie
{
    Trie *children[26];
    int index;
    int length;
 
public:
    Trie()
    {
        index = length = INT32_MAX;
        memset(children, 0, sizeof(children));
    }

    ~Trie()
    {
        for (int i = 0; i < 26; i++) {
            if (children[i]) {
                delete children[i];
            }
        }
    }

    void add(const string &s, int index)
    {
        Trie *tmp = this;
        // head
        if (tmp->length > s.size())
        {
            tmp->length = s.size();
            tmp->index = index;
        }
        for (int i = 0; i < s.size(); i++)
        {
            int j = s[i] - 'a';
            if (tmp->children[j] == nullptr)
            {
                tmp->children[j] = new Trie;
            }
            tmp = tmp->children[j];
            if (tmp->length > s.size())
            {
                tmp->length = s.size();
                tmp->index = index;
            }
        }
    }

    int search(const string &s)
    {
        Trie *tmp = this;
        int index = tmp->index;
        for (int i = 0; i < s.size(); i++)
        {
            int j = s[i] - 'a';
            tmp = tmp->children[j];
            if (!tmp) {
                break;
            }
            index = tmp->index;
        }
        return index;
    }

    void print()
    {
        cout << print(this) << endl;
    }

    string print(Trie *t)
    {
        bool found = false;
        string tmp = "[";
        for (int i = 0; i < 26; i++)
        {
            if (t->children[i])
            {
                found = true;
                tmp += char(i + 'a');
                tmp += print(t->children[i]);
            }
        }
        tmp += "]";
        if (found)
        {
            return tmp;
        }
        return "";
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery)
    {
        Trie trie;
        for (int containerIndex = 0; containerIndex < wordsContainer.size(); containerIndex++)
        {
            string &container = wordsContainer[containerIndex];
            reverse(container.begin(), container.end());
            //cout << "Adding: " << container << endl;
            trie.add(container, containerIndex);
        }
        //trie.print();

        vector<int> result;
        result.reserve(wordsQuery.size());

        for (int queryIndex = 0; queryIndex < wordsQuery.size(); queryIndex++)
        {
            string &query = wordsQuery[queryIndex];
            reverse(query.begin(), query.end());
            int index = trie.search(query);
            result.push_back(index);
        }
        return result;
    }
};