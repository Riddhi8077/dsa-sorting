class Robot {
private:
    int w, h, perim;
    long long totalSteps;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        perim = 2 * (w + h) - 4;
        totalSteps = 0;
    }

    void step(int num) {
        totalSteps += num;
    }

    vector<int> getPos() {
        int pos = totalSteps % perim;
        int p = pos;

        if (p < w) return {p, 0};
        p -= w;

        if (p < h - 1) return {w - 1, p + 1};
        p -= (h - 1);

        if (p < w - 1) return {w - 2 - p, h - 1};
        p -= (w - 1);

        return {0, h - 2 - p};
    }

    string getDir() {
        if (totalSteps == 0) return "East";

        int pos = totalSteps % perim;
        if (pos == 0) return "South";

        int p = pos;

        if (p < w) return "East";
        p -= w;

        if (p < h - 1) return "North";
        p -= (h - 1);

        if (p < w - 1) return "West";
        return "South";
    }
};
