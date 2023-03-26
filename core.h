#ifndef GUARD_core_h
#define GUARD_core_h

#include <string>
#include <vector>
#include <iostream>

class Core {
public:
    Core(): midterm(0), final_exam(0) {}
    Core(std::istream& in) { read(in); }
    virtual ~Core() {}

    std::string name() const;
    virtual std::istream& read(std::istream&);
    virtual double grade() const;

protected:
    double midterm, final_exam;
    std::vector<double> homework;
    std::istream& read_common(std::istream&);

private:
    std::string n;
};

class Grad: public Core {
public:
    Grad(): thesis(0) {};
    Grad(std::istream& in) { read(in); }
    double grade() const;
    std::istream& read(std::istream&);

private:
    double thesis;
};

bool compare(const Core&, const Core&);
bool compare_ptr(const Core*, const Core*);

#endif
