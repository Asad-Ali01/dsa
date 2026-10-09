#include <iostream>
#include <vector>
using namespace std;
class Array
{
private:
    int row;
    int column;
    vector<vector<int>> arr;
    int currentSize;

public:
    Array(int row, int column)
    {
        this->row = row;
        this->column = column;
        currentSize = 0;
        arr.resize(row, vector<int>(column, 0));
    }

    void insert(int r, int c, int value)
    {
        if (r < 0 || r >= row || c < 0 || c >= column)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (arr[r][c] != 0)
        {
            cout << "This index already occupied. Failed to insert!" << endl;
            return;
        }
        arr[r][c] = value;
        currentSize++;
        cout << value << " inserted at [" << r << "][" << c << "]. Total element: " << currentSize << endl;
    }

    void updateByIndex(int r, int c, int value)
    {
        if (r < 0 || r >= row || c < 0 || c >= column)
        {
            cout << "Invalid position!.Failed to update" << endl;
            return;
        }

        arr[r][c] = value;
        cout << value << " updated at [" << r << "][" << c << "] successfully" << endl;
    }

    void deleteByValue(int value)
    {
        if (currentSize == 0)
        {
            cout << "Array is empty. Nothing to delete." << endl;
            return;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (arr[i][j] == value)
                {
                    // Shift row elements left
                    for (int k = j; k < column - 1; k++)
                    {
                        arr[i][k] = arr[i][k + 1];
                    }
                    arr[i][column - 1] = 0;
                    currentSize--;

                    cout << value << " deleted from array. Current size: " << currentSize << endl;
                    return;
                }
            }
        }
    }

    void create()
    {

        arr.resize(row, vector<int>(column));
        for (int i = 0; i < row; i++)
        {
            cout << "*********Row " << i + 1 << " ********" << endl;
            for (int j = 0; j < column; j++)
            {
                cout << "Enter column " << j + 1 << " value of row" << i + 1 << " : ";
                cin >> arr[i][j];
            }
            cout << endl;
        }
    }

    void updateByValue()
    {
        int oldVal, newVal;
        cout << "Enter oldValue to update: ";
        cin >> oldVal;
        cout << "Enter new Value to update: ";
        cin >> newVal;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (arr[i][j] == oldVal)
                {
                    arr[i][j] = newVal;
                    return;
                }
            }
        }
    }

    void updateByIndexes()
    {
        int rowIndex, colIndex, updValue;
        cout << "Enter row index: ";
        cin >> rowIndex;
        if (rowIndex > row)
        {
            cout << "\nRow Index is out range" << endl;
        }
        cout << "Enter column index: ";
        cin >> colIndex;
        if (colIndex > column)
        {
            cout << "\nColumn Index is out range" << endl;
        }
        cout << "Enter updated value: ";
        cin >> updValue;

        cout << endl;

        arr[rowIndex][colIndex] = updValue;
    }

    void currentSizeOfElementsInArray()
    {
        cout << "Current size is: " << currentSize << endl;
    }
    void print()
    {
        cout << "Print function" << endl;
        for (int i = 0; i < row; i++)
        {
            cout << "Row " << i + 1 << endl;
            for (int j = 0; j < column; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int row, column;
    cout << "Enter row size: ";
    cin >> row;
    cout << "Enter column size: ";
    cin >> column;
    Array arr(row, column);
    arr.insert(0, 0, 10);
    arr.insert(0, 1, 10);

    arr.print();
    arr.currentSizeOfElementsInArray();
    arr.deleteByValue(10);
    arr.print();
    // arr.create();
    // arr.print();

    // // arr.updateByValue();
    // arr.updateByIndexes();
    // arr.print();
}