#include <string>
#include <iostream>
// Note: to get this to work on hills, you will need to #include <stdexcept>
#include <stdexcept>
using namespace std;

template <class ItemType>
class Box
{
private:
    ItemType item;

public:
    void setItem(const ItemType &i)
    {
        item = i;
    }
    ItemType getItem() const
    {
        return item;
    }
};
// Implement the findBox function discussed in the videos/pdfs. 
//Instead of an array of Boxes containing strings, i.e. Box<string>, however, we want to search an array of Boxes containing ints, i.e. Box<int>.
Box<int> findBox(Box<int> boxes[], int size, int target)
{
    if (target < 0)
    {
        throw logic_error("target cannot be negative");
    }
    int i = 0;
    bool found = false;
    while (!found && (i < size))
    {
        if (target == boxes[i].getItem())
            found = true;
        else
            i++;
    }
    return boxes[i];
}
int main()
{
    Box<int> intBox[5];
    // Each box contains an int representing a social security number, and thus cannot be negative. Throw another logic_error exception if the user tries to search for a negative number.
    intBox[0].setItem(731032330);
    intBox[1].setItem(619047842);
    cout << intBox[0].getItem() << endl;
    // Write a main() function to set up a small array of Box<int> elements, and use your findBox function inside of a try-catch block. Test out your catch block by entering invalid inputs,
    // i.e. negative numbers and numbers that aren't in your Box array.
    try
    {
        Box<int> result = findBox(intBox, 2, 619047842);
        cout << result.getItem() << endl;
        Box<int> result2 = findBox(intBox, 2, -619047842);
    }
    catch (logic_error e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
/*SAMPLE OUTPUT
731032330
619047842
target cannot be negative
Process exited with status 0
logout
 */
