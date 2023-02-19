/*
5
3
[1,4,3,2]
[2,6,3,1]
2
4
[1]
[3]
5
3
[1,4]
[2,5]
1
1
[1,1,1,1]
[1,1,1,50]
*/

/*
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sum1 = 0;
        int sum2 = initialExperience;
        int IEng = initialEnergy;
        int IExp = initialExperience;
        for(int i = 0; i < energy.size(); i++){
            sum1 = sum1 + energy[i];
        }

        for(int i = 0; i < experience.size(); i++){
            if(sum2 < experience[i]){
                if(i == 0){
                    int res = (experience[i] - initialExperience);
                    initialExperience = initialExperience + res + 1;
                }
                else{
                    initialExperience = (experience[i]-sum2)  + experience[i-1];
                    sum2 = initialExperience + experience[i-1] + experience[i];
                    continue;
                }
            }
            sum2 = initialExperience + experience[i];
        }


        if(sum1 >= initialEnergy){
            initialEnergy = (sum1 + 1) - initialEnergy;
        }
        if(initialExperience != IExp){
            initialExperience = initialExperience-IExp;
        }

        if(sum1 < initialEnergy && initialExperience == IExp){
             return 0;
        }


        return  initialEnergy + initialExperience;
    }
};
*/
