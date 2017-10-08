//
//  main.cpp
//  PRG-8-3-Lottery-Winners-Binary
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Modify the program you wrote for Programming Challenge 2 (Lottery Winners) so it
//  performs a binary search instead of a linear search.

#include <iostream>

using namespace std;

const int INT_ARRAY_SIZE = 8;

int getLotteryWinner();
bool compareLotteryNumbers(const int[], const int, int);

int main()
{
    bool booIsWinner;
    
    int intLotteryWinner;
    int intLotteryChoices[INT_ARRAY_SIZE] = {13579, 26791, 33445, 55555,
                                             62483, 77777, 85647, 93121};
    
    intLotteryWinner = getLotteryWinner();
    
    booIsWinner = compareLotteryNumbers(intLotteryChoices, INT_ARRAY_SIZE, intLotteryWinner);
    
    if(booIsWinner != true)
    {
        cout << "Sorry, your numbers did not match this week's winning number.\n";
    }
    else if(booIsWinner == true)
    {
        cout << "Congratulations! One of your numbers matched this weeks winning number!\n";
    }
    else
    {
        cout << "ERROR CHECKING BOOL" << endl;
    }
    
    return 0;
}

int getLotteryWinner()
{
    int intWinningNumber;
    
    cout << "Please enter the winning lottery number this week: ";
    cin >> intWinningNumber;
    while(!intWinningNumber || intWinningNumber < 10000 || intWinningNumber > 99999)
    {
        cout << "Please enter a number between 10000 and 99999: ";
        cin.clear();
        cin.ignore();
        cin >> intWinningNumber;
    }
    
    return intWinningNumber;
}

bool compareLotteryNumbers(const int intArray[], const int INT_SIZE, int intWinner)
{
    int first = 0;
    int last = INT_SIZE - 1;
    int middle;
    int position = -1;
    
    bool found = false;
    
    while(!found && first <= last)
    {
        middle = (first + last) / 2;
        if(intArray[middle] == intWinner)
        {
            found = true;
            position = middle;
        }
        else if(intArray[middle] > intWinner)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    
    return found;
}

