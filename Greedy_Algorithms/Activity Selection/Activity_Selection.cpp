#include &lt; bits / stdc++.h & gt;
using namespace std;

struct process
{
    int start;
    int finish;
};

bool compare(process p1, process p2)
{
    if (p1.finish > p2.finish)
        return true;
    return false;
}

int solve(int n, process p[])
{
    sort(p, p + n, compare); //sort the process according to finish
    time int ans = 1;
    process curr = p[0];
    for (int i = 1; i < n; i++)
    {
        if (p[i].start > curr.finish)
        {
            curr = p[i];
            ans++;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    process p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i].start >> p[i].finish;
    int temp = solve(n, p);
    cout << "Max Process Performed by a Processor " << temp << endl;
}