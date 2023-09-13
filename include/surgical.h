#ifndef DATE_H
#define DATE_H

struct PointXY {
    double x;
    double y;
};

struct SurgicalData {
private:
    PointXY beg;
    PointXY end;
public:
    void setPoints();

    void doFirstHemostat() const;

    void doFirstTweezers() const;

    void doSecondHemostat() const;

    void doSecondTweezers() const;

    void doSuture() const;

    void doScalpel();

    void start();
};

#endif