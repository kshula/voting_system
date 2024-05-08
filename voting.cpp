#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Define a Voter class to represent a voter
class Voter {
private:
    string name;
    bool hasVoted;

public:
    Voter(const string& voterName)
        : name(voterName), hasVoted(false) {}

    const string& getName() const { return name; }
    bool getHasVoted() const { return hasVoted; }
    void setHasVoted(bool voted) { hasVoted = voted; }
};

// Define a VotingSystem class to manage the voting process
class VotingSystem {
private:
    vector<Voter> voters;
    map<string, int> candidateVotes;

public:
    // Function to add a voter to the system
    void addVoter(const string& name) {
        voters.push_back(Voter(name));
    }

    // Function to add a candidate to the list of candidates
    void addCandidate(const string& candidateName) {
        candidateVotes[candidateName] = 0; // Initialize votes for the candidate to zero
    }

    // Function to cast a vote for a candidate
    void vote(const string& voterName, const string& candidateName) {
        // Find the voter by name
        auto it = find_if(voters.begin(), voters.end(),
                          [&voterName](const Voter& v) { return v.getName() == voterName; });

        if (it != voters.end() && !it->getHasVoted()) {
            // Voter found and has not voted yet
            it->setHasVoted(true); // Mark the voter as voted

            // Increment the vote count for the candidate
            if (candidateVotes.count(candidateName) > 0) {
                candidateVotes[candidateName]++;
                cout << "Vote cast by " << voterName << " for " << candidateName << endl;
            } else {
                cout << "Candidate " << candidateName << " not found." << endl;
            }
        } else {
            cout << "Invalid voter or voter has already voted." << endl;
        }
    }

    // Function to display the election results
    void displayResults() const {
        cout << "Election Results:" << endl;
        for (const auto& pair : candidateVotes) {
            cout << pair.first << ": " << pair.second << " votes" << endl;
        }
    }
};

int main() {
    // Create a voting system
    VotingSystem votingSystem;

    // Add voters
    votingSystem.addVoter("Alice");
    votingSystem.addVoter("Bob");
    votingSystem.addVoter("Charlie");

    // Add candidates
    votingSystem.addCandidate("Candidate A");
    votingSystem.addCandidate("Candidate B");
    votingSystem.addCandidate("Candidate C");

    // Perform voting
    votingSystem.vote("Alice", "Candidate A");
    votingSystem.vote("Bob", "Candidate B");
    votingSystem.vote("Charlie", "Candidate A");

    // Display results
    votingSystem.displayResults();

    return 0;
}
