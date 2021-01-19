#ifndef OTHERCLASS_H
#define OTHERCLASS_H

class otherClass{
    public:
        otherClass( float val )
            :val{val}
        {}
        virtual float method_to_check( int id ) const;

    private:
        float val;
        int id;
};

#endif