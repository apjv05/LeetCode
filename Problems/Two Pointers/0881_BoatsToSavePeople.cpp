int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int Boats = 0, a = 0, b = people.size() - 1;
    
    while(a <= b) {
        //weight left in our current boat
        //and decrement to move to the next person
        int remain = limit - people[b--];

        //use another boat
        Boats++;

        //can the lightest person fit into the boat?
        //if they can we can incremement to the next person

        //as long as there is a person left and we can hold them
        //increment to the next person
        if(a <= b && remain >= people[a]) a++;
    }
    return Boats;
}