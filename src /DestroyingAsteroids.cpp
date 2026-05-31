class Solution {
public:
    bool xorGame(int mass, vector<int>& asteroids) {
        return asteroidsDestroyed(mass, asteroids);
    }

    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        for (int asteroid : asteroids) {
            if (mass < asteroid) {
                return false;
            }
            mass += asteroid;
        }

        return true;
    }
};
