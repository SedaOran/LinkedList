#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

struct AwayMinuteID{
    string away_team;
    string goal_minute;
    string match_ID;
    AwayMinuteID *prev;
    AwayMinuteID *next;
};
struct FootTeamName{
    string footballer_name;
    string team_name;
    AwayMinuteID *nextlink;
    AwayMinuteID *taillink;
    FootTeamName *next;
};

class linked_list
{
private:
    FootTeamName *head,*tail;
public:
  //  FootTeamName *head,*tail;
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(string footballer_name , string team_name ,string away_team , string goal_minute , string match_ID)
    {

        AwayMinuteID *goal = new AwayMinuteID();
        goal->prev = NULL;
        goal->next = NULL;
        goal->away_team = away_team;
        goal->goal_minute = goal_minute;
        goal->match_ID = match_ID;
        int flag = 0;
        if(head != NULL){
            FootTeamName *head_tmp=new FootTeamName();
            head_tmp= this->head;
            while(head_tmp != NULL && head_tmp != NULL){
                if(head_tmp->footballer_name.compare(footballer_name)==0){
                    flag = 1;
                    head_tmp->taillink->next = goal;
                    head_tmp->taillink = head_tmp->taillink->next;
                }
                head_tmp = head_tmp->next;
            }
        }
        if(flag == 0){
            FootTeamName *tmp = new FootTeamName();
            tmp->footballer_name = footballer_name;
            tmp->team_name = team_name;
            tmp->next = NULL;
            tmp->nextlink = NULL;
            tmp->taillink = NULL;
            if(head == NULL)
            {
                tmp->nextlink = goal ;
                tmp->taillink = goal ;
                head = tmp;
                tail = tmp;
            }
            else
            {
                tmp->nextlink = goal ;
                tmp->taillink = goal ;
                tail->next = tmp;
                tail = tail->next;
            }
        }
    }
    void display()
    {
        FootTeamName *temp=new FootTeamName();
        temp=head;
        int second_half = 0;
        int first_half = 0;
        while(temp!=NULL)
        {
        AwayMinuteID* seda = temp->nextlink;
        while(seda != NULL){
                string b = seda->goal_minute;
                stringstream geek(b);
                int x = 0;
                geek >> x;
                if(x > 45){
                    second_half++;
                }
                else if(x <= 45 ){
                first_half++;
                }
            seda = seda->next;
        }
        temp=temp->next;
        }
        if(first_half > second_half){
            cout<<"1)THE MOST SCORED HALF \n" ;
            cout<<"0\n";
        }
        else{
            cout<<"1)THE MOST SCORED HALF \n" ;
            cout<<"1\n";
        }
    }
    void diplayFootballers(){
        cout<<"5)LIST OF FOOTBALLERS\n";
         FootTeamName *temp=new FootTeamName();
        temp=head;
        while(temp!=NULL)
        {
        cout<<temp->footballer_name<<"\n";
        temp=temp->next;
        }
    }
    int mostScorer(){
        FootTeamName *temp=new FootTeamName();
        temp=head;
        int counter=0;
        int lastcounter=0;
        while(temp!=NULL)
            {
            AwayMinuteID* linktoScore = temp->nextlink;
            while(linktoScore != NULL){
                    counter++;
                linktoScore = linktoScore->next;
            }

            if(counter > lastcounter){
                lastcounter = counter;
            }
            counter=0;
            temp=temp->next;
            }
        return lastcounter;
    }
    void displayMostScorer(int i){
        FootTeamName *tmp=new FootTeamName();
        tmp=head;
        cout<<"2)GOAL SCORER\n";
        int counter=0;
        while(tmp!=NULL)
        {
        AwayMinuteID* countertmp = tmp->nextlink;
        while(countertmp != NULL){
                counter++;
            countertmp= countertmp->next;
        }
        if(counter==i){
            cout<<tmp->footballer_name<<endl;
        }
        counter=0;
        tmp=tmp->next;
        }
    }



    void displayHatTrick(){
        FootTeamName *temp=new FootTeamName();
        temp=head;
        int say;
      //  int hattrick;
        cout<<"3)THE NAMES OF FOOTBALLERS WHO SCORED HAT-TRICK\n";
        while(temp!=NULL)
            {
                say=0;
            std::vector<int> arrayofIDs;
            AwayMinuteID* counterHatTrick = temp->nextlink;
            while(counterHatTrick != NULL){
                    string b = counterHatTrick->match_ID;
                    stringstream geek(b);
                    int x = 0;
                    geek >> x;
                    arrayofIDs.push_back(x);
                    counterHatTrick= counterHatTrick->next;
            }
        for(int i =0 ; i <(signed)arrayofIDs.size() ; i++){
                for(int j = i ; j < (signed)arrayofIDs.size()-i ; j++){
                   if(arrayofIDs[i]==arrayofIDs[j]){
                    say++;
                   }
                }
        }
        if(say >= 3){
            cout<<temp->footballer_name;
            cout<<"\n";
        }
      //  hattrick=0;
        temp=temp->next;
        }
 }

        void displayMatchesOfFootballer(string footballername){
            FootTeamName *temp=new FootTeamName();
            temp=head;
            while(temp!=NULL)
            {
                if(footballername.compare(temp->footballer_name) == 0){
                    cout<<"Matches of ";
                    cout<<temp->footballer_name<<endl;
                    AwayMinuteID* other = temp->nextlink;
                    while(other != NULL){
                        cout<<"Footballer name: ";
                        cout<<temp->footballer_name;
                        cout<<",Away Team: ";
                        cout<<other->away_team;
                        cout<<",Min Of Goal: ";
                        cout<<other->goal_minute;
                        cout<<",Match ID: ";
                        cout<<other->match_ID;
                        cout<<"\n";
                        other = other->next;
                    }
                }

                temp=temp->next;
            }
        }
        void displayAscendingOrder(string ascendingitem){
            FootTeamName *temp=new FootTeamName();
            temp=head;
            while(temp!=NULL)
            {
                if(ascendingitem.compare(temp->footballer_name) == 0){
                        std::vector<string> arrayofascending;
                        std::vector<int> arrayofascendingint;

                    AwayMinuteID* ascending = temp->nextlink;
                    while(ascending != NULL){
                            string b = ascending->match_ID;
                            arrayofascending.push_back(b);
                            stringstream geek(b);
                            int x = 0;
                            geek >> x;
                            arrayofascendingint.push_back(x);
                            ascending = ascending->next;
                    }
                    sort(arrayofascendingint.begin(), arrayofascendingint.end());
                    for(int i =0 ; i< (signed)arrayofascendingint.size() ; i++){
                            if(arrayofascendingint[i]!=arrayofascendingint[i+1]){
                            cout<<"footballer Name: ";
                            cout<<temp->footballer_name;
                            cout<<",Match ID: ";
                            cout<<arrayofascendingint[i];
                            cout<<"\n";
                        }
                    }
                }
                temp=temp->next;
            }
        }

        void displayDescendingOrder(string descendingitem){
            FootTeamName *temp=new FootTeamName();
            temp=head;
            while(temp!=NULL)
            {
                if(descendingitem.compare(temp->footballer_name) == 0){
                        std::vector<string> arrayofdescending;
                        std::vector<int> arrayofdescendingint;

                    AwayMinuteID* descending = temp->nextlink;
                    while(descending != NULL){
                            string b = descending->match_ID;
                            arrayofdescending.push_back(b);
                            stringstream geek(b);
                            int x = 0;
                            geek >> x;
                            arrayofdescendingint.push_back(x);
                            descending = descending->next;
                    }
                    std::sort(arrayofdescendingint.rbegin(), arrayofdescendingint.rend());

                            for(int i =0 ; i<(signed) arrayofdescendingint.size() ; i++){

                           if(arrayofdescendingint[i]!=arrayofdescendingint[i+1]){
                            cout<<"footballer Name: ";
                            cout<<temp->footballer_name;
                            cout<<",Match ID: ";
                            cout<<arrayofdescendingint[i];
                            cout<<"\n";
                        }
                    }
                }
                temp=temp->next;
            }}
};
int partition (vector<vector<string> >& arr, int low, int high)
{
    vector<string> pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j][0] <= pivot[0])
        {
            i++;
            arr[i].swap(arr[j]);
        }
    }
    arr[i+1].swap(arr[high]);
    return (i + 1);
}

void quickSort(vector<vector<string> >& arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int findInArray(std::vector<string> arrayofteams , string item){
    int flag=0;
        for(int a =0 ; a < (signed)arrayofteams.size() ; a++){
            if(arrayofteams[a].compare(item)!=0){
                flag=1;
            }
            else{
                flag=0;
                break;
            }
        }
    return flag;
}
int main (int argc, char** argv )
{
    std::vector<std::vector<string> > array;
    std::vector<std::vector<string> > arrayofoperations;
    std::string line;
    ifstream file( argv[1] );
    ifstream fileoperations( argv[2]);
    int number_of_lines=0;
    while ( std::getline(file, line) )
    {
        number_of_lines++;
        std::vector<string> row;
        std::istringstream ss(line);
        while ( ss)
        {
                string s;
        if (!getline( ss, s, ',' )) break;
        row.push_back( s );
        }
         array.push_back(row);
    }
    quickSort(array,0,array.size()-1);

    while ( std::getline(fileoperations, line) )
    {
        std::vector<string> rowoperation;
        std::istringstream ss(line);
        while ( ss)
        {
                string s;
        if (!getline( ss, s, ',' )) break;
        rowoperation.push_back( s );
        }
         arrayofoperations.push_back(rowoperation);
    }
    linked_list a ;
    for(int c =0 ; c <(signed) array.size() ; c++){
          a.add_node(array[c][0],array[c][1],array[c][2],array[c][3],array[c][4]);
    }
    std::vector<string> arrayofteams;
    arrayofteams.push_back(array[0][1]);

    for(int a =0 ; a < number_of_lines ; a++){
       if( findInArray(arrayofteams,array[a][1]) ==1) {
        arrayofteams.push_back(array[a][1]);
       }
    }

    for(int a =0 ; a < number_of_lines ; a++){
        if( findInArray(arrayofteams,array[a][2]) ==1) {
        arrayofteams.push_back(array[a][2]);
       }
    }
freopen("output.txt","w",stdout);
    int c;
    a.display();
    c = a.mostScorer();
    a.displayMostScorer(c);
    a.displayHatTrick();
    //WRITE TEAM NAMES
    cout<<"4)LIST OF TEAMS";
    cout<<"\n";
    for(int i =0 ; i <(signed) arrayofteams.size() ; i++){
        cout<<arrayofteams[i]+"\n";
    }
    a.diplayFootballers();
    //""666666666666  MATCHES OF GÝVEN FOOTBALLER
    cout<<"6)MATCHES OF GIVEN FOOTBALLER"<<endl;
    for(int i =0 ; i<(signed)arrayofoperations[0].size() ; i++ ){
        a.displayMatchesOfFootballer(arrayofoperations[0][i]);
    }
    cout<<"7)ASCENDING ORDER ACCORDING TO MATCH ID"<<endl;
    for(int i =0 ; i<(signed)arrayofoperations[1].size() ; i++ ){
        a.displayAscendingOrder(arrayofoperations[1][i]);
    }
    cout<<"8)DESCENDING ORDER ACCORDING TO MATCH ID"<<endl;
    for(int i =0 ; i<(signed)arrayofoperations[2].size() ; i++ ){
        a.displayDescendingOrder(arrayofoperations[2][i]);
    }




}
