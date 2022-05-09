#include <iostream>
#include "../include/bunny.h"
#include <map>
#include <vector>
#include <ctime>
#include <random>
#include <stdlib.h>
//#include <iostream.h>
// passs in initalisation list look at static example
// can have random before and add in
// initalisation list
bunny::bunny()
{
    age = 0;
    // change random
    // change m_ stuff to function and do not store,
    // change radioactve to true/ false

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 1);
    int randomNumber = dist2(rng);
    if (randomNumber == 0)
    {
        i_sex = e_sex::male;
    }
    else
    {
        i_sex = e_sex::female;
    }
    std::map<int, std::string> S{{0, "Male"}, {1, "Female"}};
    m_sex = S[i_sex];

    // change to bool
    std::uniform_int_distribution<std::mt19937::result_type> dist100(0, 99); // distribution in range [1, 6]
    randomNumber = dist100(rng);
    if (randomNumber > 1)
    {
        i_radioactive = e_radioactive::normal;
        // radioactive = false;
    }
    else
    {
        i_radioactive = e_radioactive::radioactive;
        // radioactive = true;
    }
    std::map<int, std::string> R{{0, "normal"}, {1, "radioactive"}};
    m_radioactive = R[i_radioactive];

    // randomNumber = rand() % 4;
    std::uniform_int_distribution<std::mt19937::result_type> dist4(0, 3); // distribution in range [1, 6]
    randomNumber = dist4(rng);

    switch (randomNumber)
    {
    case 0:
        i_colour = e_colour::white;
        break;
    case 1:
        i_colour = e_colour::brown;
        break;
    case 2:
        i_colour = e_colour::black;
        break;
    case 3:
        i_colour = e_colour::spotted;
        break;
    }
    std::map<int, std::string> C{{0, "White"}, {1, "Brown"}, {2, "Black"}, {3, "Spotted"}};
    m_colour = C[i_colour];
    // write this at time of need.. can do this to all the M's
    bunny::SetName();
}

void bunny::turnRadioactive()
{
    i_radioactive = e_radioactive::radioactive;
    bunny::SetRadioactive();
}

void bunny::SetRadioactive()
{
    std::map<int, std::string> R{{0, "normal"}, {1, "radioactive"}};
    m_radioactive = R[i_radioactive];
}

/*void bunny::SetSex()
{
    std::map<int, std::string> S{{0, "Male"}, {1, "Female"}};
    m_sex = S[i_sex];
}*/

/*void bunny::SetColour()
{
    std::map<int, std::string> C{{0, "White"}, {1, "Brown"}, {2, "Black"}, {3, "Spotted"}};
    m_colour = C[i_colour];
}*/
void bunny::SetColour(int colour)
{
    switch (colour)
    {
    case 0:
        i_colour = e_colour::white;
        break;
    case 1:
        i_colour = e_colour::brown;
        break;
    case 2:
        i_colour = e_colour::black;
        break;
    case 3:
        i_colour = e_colour::spotted;
        break;
    }
    std::map<int, std::string> C{{0, "White"}, {1, "Brown"}, {2, "Black"}, {3, "Spotted"}};
    m_colour = C[i_colour];
}

void bunny::SetName()
{

    std::vector<std::string> names{"Ace",
                                   "Alaska",
                                   "Alexander",
                                   "Alfalfa",
                                   "Alfie",
                                   "Appollo",
                                   "Archie",
                                   "Arnold",
                                   "Asterix",
                                   "Audi",
                                   "Auggie",
                                   "Bagel",
                                   "Baloo",
                                   "Bam Bam",
                                   "Bandit",
                                   "Barcode",
                                   "Barney",
                                   "Bear",
                                   "Benjamin",
                                   "Benji",
                                   "Benny",
                                   "Bilbo",
                                   "Billy",
                                   "Black Beard",
                                   "Blackie",
                                   "Blackjack",
                                   "Blaze",
                                   "Bob",
                                   "Boston",
                                   "Breeze",
                                   "Bruce",
                                   "Bruno",
                                   "Buddy",
                                   "Bugs Bunny",
                                   "Bugster",
                                   "Bugsy",
                                   "Bun Bun",
                                   "Buster",
                                   "Butters",
                                   "Cadbury",
                                   "Caesar",
                                   "Caramel",
                                   "Carter",
                                   "Charlie",
                                   "Chesswood",
                                   "Chester",
                                   "Chewbacca",
                                   "Chip",
                                   "Chomper",
                                   "Chubby",
                                   "Claude",
                                   "Cloudy",
                                   "Cole",
                                   "Comet",
                                   "Cookie",
                                   "Cooper",
                                   "Copper",
                                   "Cosby",
                                   "Cotton Puff",
                                   "Dallas",
                                   "Dalton",
                                   "Dante",
                                   "Darryl",
                                   "Delboy",
                                   "Delta",
                                   "Denzel",
                                   "Dexter",
                                   "Dobby",
                                   "Domino",
                                   "Donald",
                                   "Draco",
                                   "Dumbo",
                                   "Duncan",
                                   "Dusty",
                                   "Echo",
                                   "Einstein",
                                   "Elvis",
                                   "Emerson",
                                   "Emmitt",
                                   "Fabio",
                                   "Fitch",
                                   "Floppy",
                                   "Flopsy",
                                   "Flumpy",
                                   "Forrest",
                                   "Fred",
                                   "Freddie",
                                   "Frodo",
                                   "Gadget",
                                   "Galaxy",
                                   "George",
                                   "Gizmo",
                                   "Goblin",
                                   "Goober",
                                   "Goofy",
                                   "Guinness",
                                   "Gus",
                                   "Hal",
                                   "Harry",
                                   "Harvey",
                                   "Henry",
                                   "Herbie",
                                   "Hermie",
                                   "Hip Hop",
                                   "Homer",
                                   "Hondo",
                                   "Honey",
                                   "Honey Bunny",
                                   "Hopper",
                                   "Hopscotch",
                                   "Houdini",
                                   "Huck",
                                   "Hudini",
                                   "Hugo",
                                   "Humphrey",
                                   "Iggy",
                                   "Jack",
                                   "Jackie",
                                   "Jake",
                                   "Jasper",
                                   "Jazz",
                                   "Jelly Bean",
                                   "Jesaja",
                                   "Jesse",
                                   "Jet",
                                   "Joey",
                                   "Jonas",
                                   "Karl",
                                   "Kirby",
                                   "Knight",
                                   "Kobie",
                                   "Kodo",
                                   "Lenny",
                                   "Leo",
                                   "Leopold",
                                   "Lone Ranger",
                                   "Lunn",
                                   "Majestic",
                                   "Marble",
                                   "Max",
                                   "Maxwell",
                                   "Merlin",
                                   "Midnight",
                                   "Milly",
                                   "Milo",
                                   "Momo",
                                   "Moody",
                                   "Moose",
                                   "Mr. Fuzzlebuns",
                                   "Murphy",
                                   "Mystic",
                                   "Nacho",
                                   "Nemo",
                                   "Nero",
                                   "Ninja",
                                   "Noel",
                                   "Noodle",
                                   "Nova",
                                   "Obelix",
                                   "Octha",
                                   "Oliver",
                                   "Ollie",
                                   "Oreo",
                                   "Oscar",
                                   "Pancake",
                                   "Patch",
                                   "Peanut",
                                   "Pepper",
                                   "Pepsi",
                                   "Peter",
                                   "Phantom",
                                   "Pillsbury",
                                   "Pippin",
                                   "Pluto",
                                   "Porter",
                                   "Porthos",
                                   "Prancer",
                                   "Prince",
                                   "Prince George",
                                   "Random",
                                   "Rascal",
                                   "Raven",
                                   "Reginald",
                                   "Rex",
                                   "Riley",
                                   "River",
                                   "Rocket",
                                   "Rocky",
                                   "Roger Rabbit",
                                   "Rolf",
                                   "Romeo",
                                   "Rosco",
                                   "Ross",
                                   "Rowdy",
                                   "Rufus",
                                   "Sage",
                                   "Sammy",
                                   "Scooter",
                                   "Scotch",
                                   "Scout",
                                   "Scruffy",
                                   "Shadow",
                                   "Shippy",
                                   "Simba",
                                   "Skippe",
                                   "Smithers",
                                   "Smokey",
                                   "Snoop",
                                   "Snoopy",
                                   "Snowball",
                                   "Snowman",
                                   "Soldier",
                                   "Solomon",
                                   "Spanky",
                                   "Spencer",
                                   "Spike",
                                   "Spirit",
                                   "Spooky",
                                   "Spot",
                                   "Stanley",
                                   "Stewart Little",
                                   "Stewie",
                                   "Stoker",
                                   "Stormy",
                                   "Stuart",
                                   "Sylvester",
                                   "Tarzan",
                                   "Teddy",
                                   "Tequila",
                                   "Tex",
                                   "Theodore",
                                   "Thor",
                                   "Thumper",
                                   "Tidbit",
                                   "Tigger",
                                   "Tinkerbell",
                                   "Toby",
                                   "Tornado",
                                   "Trumpet",
                                   "Turbo",
                                   "Uncle Buck",
                                   "Waldo",
                                   "Winston",
                                   "Wolfgang",
                                   "Wonka",
                                   "Yoda",
                                   "Yogi",
                                   "Zero",
                                   "Ziggy",
                                   "Zorro"};

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> FirstDist(0, names.size() - 1); // distribution in range [1, 6]
    int randomNumber = FirstDist(rng);
    std::string firstName = names.at(randomNumber);
    std::uniform_int_distribution<std::mt19937::result_type> LastDist(0, names.size() - 1); // distribution in range [1, 6]
    randomNumber = LastDist(rng);
    std::string secondName = names.at(randomNumber);
    name = firstName + " " + secondName;
}

void bunny::SetAge()
{
    age++;
}
