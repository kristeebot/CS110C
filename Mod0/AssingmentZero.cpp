// This simple class has two member variables and four member functions to set and get the variables.
// Implement a complete C++ program which declares this class and implements all four of its member functions.
#include <string>
#include <iostream>
using namespace std;

class Song
{
private:
    string artist;
    string song;

    // setName should change member variable name to the parameter n
    // setArtist should change member variable artist to the parameter a
public:
    void setName(string n)
    {
        song = n;
    }
    void setArtist(string a)
    {
        artist = a;
    }
    // getName should return member variable name
    string getName()
    {
        return song;
    }
    // getArtist should return member variable artist
    string getArtist()
    {
        return artist;
    }
};

int Ass1main()
{
    // Then, create a simple main() program which creates an object of the class, asks the user for name and artist,
    // calls the set functions to assign reasonable values for name and artist, and then calls the get functions to output both name and artist to the console.
    Song mySong;

    const int buf_max = 100;
    char input[buf_max];

    cout << "Please enter the name of the song: ";
    cin.getline(input, buf_max);
    mySong.setName(input);

    cout << "Please enter the name of the artist: ";
    cin.getline(input, buf_max);
    mySong.setArtist(input);

    cout << mySong.getArtist() << endl;
    cout << mySong.getName() << endl;
    return 0;
}

/*SAMPLE OUTPUT
Please enter the name of the song: Mama Tried
Please enter the name of the artist: Merle Haggard
Merle Haggard
Mama Tried
Process exited with status 0
*/