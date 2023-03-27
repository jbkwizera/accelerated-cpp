#ifndef GUARD_core_h
#define GUARD_core_h

#include <string>
#include <vector>
#include <iostream>

class Core {
    friend class CoreHandle;

public:
    Core(): midterm(0), final_exam(0), total(0) {}
    Core(std::istream& in) { read(in); }
    virtual ~Core() {}

    std::string name() const;
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
    virtual double grade_mean() const;
    virtual double grade_optimistic_median() const;
    virtual bool did_all_homework() const;
    virtual bool pass() const;

protected:
    double midterm, final_exam, total;
    static const int PassGrade = 60;
    std::vector<double> homework;

    std::istream& read_common(std::istream&);
    virtual Core* clone() const { return new Core(*this); }

private:
    std::string n;
};

class Grad: public Core {
public:
    Grad(): thesis(0) {}
    Grad(std::istream& in) { read(in); }
    double grade() const;
    std::istream& read(std::istream&);

protected:
    Grad* clone() const { return new Grad(*this); }

private:
    double thesis;
};

class Credit: public Core {
public:
    Credit() {}
    Credit(std::istream& in) { read(in); }

    std::istream& read(std::istream&);
    double grade() const;

protected:
    Credit* clone() const { return new Credit(*this); }
};

#endif
