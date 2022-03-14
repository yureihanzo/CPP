#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // the set up for the story of the game is as follows:
    std::cout << "\n\nYou are a memeber of section 3Difficulty and you are trying to get into the secure projects section of the computer core. The core is under a Level " << Difficulty;
    std::cout << " encryption key you are trying to crack.\nYou must enter the correct encription key to gain access\n\n";

}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // declare three number code
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    //out print of the sum and product
    std::cout << "+There are three numbers in the code";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // store user input
    int GuessA, GuessB, GuessC;
    
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou have passed this level of encryption.";
        return true;
    }
    else
    {
        std::cout << "\nBe careful they are becomeing alerted! Try again!";
        return false;
    }
}



int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 20;

    while (LevelDifficulty <= MaxDifficulty)// loop game untill all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore();// Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "\nYou have gained entry.";
    
    return 0;
}