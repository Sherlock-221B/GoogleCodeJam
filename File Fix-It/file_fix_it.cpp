#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class dir
{
  public:
    string name;
    dir *firstChild;
    dir *nextSibling;

    dir(string name) : name(name), firstChild(NULL), nextSibling(NULL)
    {
    }
    dir *add_child(string dirname)
    {
        dir *child = new dir(dirname);
        if (firstChild == NULL)
        {
            firstChild = child;
        }
        else
        {
            dir *temp = firstChild;
            while (temp->nextSibling != NULL)
                temp = temp->nextSibling;
            temp->nextSibling = child;
        }
        return child;
    }

    dir *find_dir(string dirname)
    {
        dir *temp = firstChild;
        while (temp != NULL)
        {
            if (temp->name == dirname)
                return temp;
            temp = temp->nextSibling;
        }
        return NULL;
    }

    void delete_all()
    {
        if (firstChild != NULL)
            firstChild->delete_all();
        if (nextSibling != NULL)
            nextSibling->delete_all();
        firstChild = nextSibling = NULL;
        delete this;
    }
};

void split(vector<string> &v, string path)
{
    int start = 1, end = 1;
    while (end < path.length())
    {
        if (path[end] == '/')
        {
            v.push_back(path.substr(start, end - start));
            start = ++end;
        }
        else
            end++;
    }
    v.push_back(path.substr(start, end - start));
}

int process(dir *d, vector<string> &v)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        dir *child = d->find_dir(v[i]); //check if v[i] exists inside d folder
        if (child == NULL)
        {
            child = d->add_child(v[i]);
            count++;
        }
        d = child;
    }
    return count;
}

int main()
{
    int T, N, M, Case = 0;
    string path;
    ifstream in("A-large-practice.in");
    streambuf *inbuf=cin.rdbuf();
    cin.rdbuf(in.rdbuf());

    ofstream out("output.txt");
    streambuf *outbuf=cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    cin >> T;
    //run through test cases
    while (T--)
    {
        dir *root = new dir("/");
        Case++;
        cin >> N >> M;
        //take already existing directory paths and store them
        while (N--)
        {
            cin >> path;
            vector<string> v;
            split(v, path);
            process(root, v);
        }
        //take new directories AND store them AND increment count while storing
        int count = 0;
        while (M--)
        {
            cin >> path;
            vector<string> v;
            split(v, path);
            count += process(root, v);
        }
        cout << "Case #" << Case << ": " << count << endl;
        root->delete_all();
    }
    cin.rdbuf(inbuf);
    cout.rdbuf(outbuf);

    return 0;
}