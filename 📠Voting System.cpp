#include <iostream>
#include <iomanip>

#define MAX_CANDIDATES 5

struct Candidate {
    char name[50];
    int votes;
};

void displayCandidates(Candidate candidates[], int numCandidates) {
    std::cout << "\n\tPolitical Party : \n";
    for (int i = 0; i < numCandidates; ++i) {
        std::cout << "Press " << i + 1 << ": To Vote for " << candidates[i].name << std::endl;
    }
}

void castVote(Candidate candidates[], int numCandidates) {
    int choice;
    displayCandidates(candidates, numCandidates);

    std::cout << "\nEnter The Number Of Your Political Party : ";
    std::cin >> choice;

    if (choice >= 1 && choice <= numCandidates) {
        candidates[choice - 1].votes++;
        std::cout << "\n\tYou Have Voted Successfully!\n\tThanks For Your Precious Vote.\n";
        std::cout << "_____________________________________________\n\n";
    } else {
        std::cout << "Invalid choice. Please try again.\n";
    }
}

void displayResults(Candidate candidates[], int numCandidates) {
    std::cout << "\n\t\tElection Results:\n";
    for (int i = 0; i < numCandidates; ++i) {
        std::cout << candidates[i].name << ": " << candidates[i].votes << " votes" << std::endl;
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES] =
    {
        {"BJP", 0},
        {"BSP", 0},
        {"AIMIM", 0},
        {"Congress", 0},
        {"Shiv Sena", 0}
    };

    int numCandidates = sizeof(candidates) / sizeof(candidates[0]);

    int choice;
    do {
        std::cout << "\n\t||••••••Voting Menu:•••••••||\nPress (1) For Voting 🗳️ \nPress (2) For Displaying The Results 😱 \nPress (3) For Exit Program🚫 \n";
        std::cout << "\nEnter Your Choice : ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            castVote(candidates, numCandidates);
            break;
        case 2:
            displayResults(candidates, numCandidates);
            break;
        case 3:
            std::cout << "\tYou Are Exited From The program.\n\t\tThank you!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
