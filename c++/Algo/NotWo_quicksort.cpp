// not working correctly  need slight changes

#include <iostream>
using namespace std;
class quickSort {
private:
    int* arr = NULL, n;

public:
    int* get();
    void sortA(int* a, int l, int h);
    int partition(int* a, int l, int h);
    void display(void) {
        cout << "final\n";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
    int use()
    {
        return n;
    }
};

int* quickSort::get()
{
    cout << "Enter the number of elements\n";
    cin >> n;
    // high = n-1;
    arr = new int(n);
    cout << "enteting\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

int quickSort::partition(int* a, int l, int h)
{
    int left = l, right, temp;
    right = h;
    int pivot = a[l];
    while (left < right)
    {
        //
        if (a[left] <= pivot)
            left++;
        if (a[right] > pivot)
            right--;
        if (left < right)
        {
            temp = arr[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }
    a[0] = a[right];
    a[right] = pivot;
    return right;
}
void quickSort::sortA(int* a, int l, int h)
{
    int pivot;
    if (h <= 0)
        return;
    if (l < h)
    {
        pivot = partition(a, l, h);
        sortA(a, l, pivot - 1);
        sortA(a, pivot + 1, h);
    }
}
int main(){
    quickSort q;
    int* a, n;
    a = q.get();
    int h = q.use();
    q.sortA(a, 0, h - 1);
    q.display();
    cout << "sort ;\n";
    for (int i = 0; i < h; i++)
    {
        cout << a[i] << "\t";
    }
}