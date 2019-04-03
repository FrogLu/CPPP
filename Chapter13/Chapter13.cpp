#include "pch.h"
#include "HasPtr.h"
#include "numbered.h"
#include "NoDtor.h" //  a class which deleted its destructor
#include "test.h"   //  a class just for testing what I meet but the book doesn't told me.
#include "Employee.h"
#include "StrBlob.h"
#include "Message.h"
#include "Folder.h"

int main()
{
    HasPtr hp1("hello"), hp2("world"), hp3("FrogLu");
    std::vector<HasPtr> hpvec = {hp1,hp2,hp3};
    std::sort(hpvec.begin(), hpvec.end());
    
    //Message msg1("hello"), msg2("world");
    //Folder inbox("inbox"), archive("archive");
    //inbox.print();
    //archive.print();

    //msg1.save(inbox);
    //inbox.print();
    //archive.print();

    //archive = inbox;
    //inbox.print();
    //archive.print();

    //msg2.save(archive);
    //inbox.print();
    //archive.print();

    //msg1.remove(archive);
    //inbox.print();
    //archive.print();

    //msg1.remove(inbox);
    //inbox.print();
    //archive.print();

    //msg2 = msg1;
    //inbox.print();
    //archive.print();

    //msg2.save(inbox);
    //inbox.print();
    //archive.print();

    return 0;
}
