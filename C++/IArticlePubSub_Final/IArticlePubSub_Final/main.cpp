#include <iostream>
#include <string>

using namespace std;

class IArticleSub;

class IArticlePub {
private:
    string pub_name;
    int pub_id;
    string recent_contents;
    static int static_pub_counter;

protected:
    IArticleSub* sub_list[5];
    int numOfSub = 0;

public:
    IArticlePub(const string name);
    IArticlePub(const string name, const string con);
    virtual ~IArticlePub();
    void NotifyAttachResponse(IArticleSub* subscriber);
    void NotifyAttach(IArticleSub* subscriber);
    void NotifyDetach(IArticleSub* subscriber);
    void NotifyDetachResponse(IArticleSub* subscriber);
    void Notify();
    void updatePubContents(string c);
    int getPubID();
    string getPubName();
    int getSubSize();
    void PrintAllSub();
    virtual void Event() = 0;
};

class IArticleSub {
private:
    string sub_name;
    int sub_id;
    static int static_sub_counter;
    IArticlePub* recent_article_pub;
    string recent_article_contents;

protected:
    IArticlePub* pub_list[5];
    int numOfPub = 0;

public:

    IArticleSub(string name) {
        this->sub_name = name;
        ++IArticleSub::static_sub_counter;
        this->sub_id = IArticleSub::static_sub_counter;
        for (int i = 0; i < 5; i++) {
            pub_list[i] = nullptr;
        }
        cout << "[Constructor]New Sub Created: (" << this->getSubName() << "," << this->getSubID() << ")" << endl;
    }

    IArticleSub(string name, IArticlePub* articlePub) {
        this->sub_name = name;
        ++IArticleSub::static_sub_counter;
        this->sub_id = IArticleSub::static_sub_counter;
        for (int i = 0; i < 5; i++) {
            pub_list[i] = nullptr;
        }
        cout << "[Constructor]New Sub Created: (" << this->getSubName() << "," << this->getSubID() << ")" << endl;
        Attach(articlePub);
    }

    ~IArticleSub() {
        cout << "IArticleSub Destructor called" << endl;
        for (int i = 0; i < numOfPub; i++) {
            pub_list[i]->NotifyDetachResponse(this); // critical point. 洹몃깷 Detach�곕㈃ iter 0 �뚭퀬 numOfPub�� 1�섎쾭�ㅼ꽌 洹몃깷 �섍�踰꾨┝. 
        }
    };

    void Attach(IArticlePub* publisher) {
        int find = -1;
        for (int i = 0; i < numOfPub; i++) {
            if (pub_list[i] == publisher) {
                find = i;
            }
        }
        if (find != -1) {
            cout << "[ERROR]: already subscribe" << publisher->getPubName() << endl;
            return;
        }
        cout << "[Attach] Pub (" << publisher->getPubName() << "," << publisher->getPubID() << ") is attached to Sub (" << this->getSubName() << "," << this->getSubID() << ")" << endl;
        pub_list[numOfPub] = publisher;
        numOfPub++;
        publisher->NotifyAttachResponse(this);
    }

    void AttachResponse(IArticlePub* publisher) {
        int find = -1;
        for (int i = 0; i < numOfPub; i++) {
            if (pub_list[i] == publisher) {
                find = i;
            }
        }
        if (find != -1) {
            cout << "[ERROR]: already subscribe" << publisher->getPubName() << endl;
            return;
        }
        cout << "[Attach] Pub (" << publisher->getPubName() << "," << publisher->getPubID() << ") is attached to Sub (" << this->getSubName() << "," << this->getSubID() << ")" << endl;
        pub_list[numOfPub] = publisher;
        numOfPub++;
    }

    void Detach(IArticlePub* p_pub) {
        int find = -1;
        for (int i = 0; i < numOfPub; i++) {
            if (pub_list[i] == p_pub) {
                find = i;
            }
        }
        if (find == -1) {
            cout << "[ERROR]: There is no publisher named" << p_pub->getPubName() << endl;
        }
        else {
            cout << "[Sub] (" << this->getSubName() << "," << this->getSubID() << ") unsubscribes [Pub] (" << p_pub->getPubName() << "," << p_pub->getPubID() << ")" << endl;
            for (int j = find; j < numOfPub - 1; j++) {
                pub_list[j] = pub_list[j + 1];
            }
            pub_list[numOfPub - 1] = nullptr;
            numOfPub--;
            p_pub->NotifyDetachResponse(this);
        }
    }

    void DetachResponse(IArticlePub* p_pub) {
        int find = -1;
        for (int i = 0; i < numOfPub; i++) {
            if (pub_list[i] == p_pub) {
                find = i;
            }
        }
        if (find == -1) {
            cout << "[ERROR]: There is no publisher named" << p_pub->getPubName() << endl;
        }
        else {
            cout << "[Sub] (" << this->getSubName() << "," << this->getSubID() << ") unsubscribes [Pub] (" << p_pub->getPubName() << "," << p_pub->getPubID() << ")" << endl;
            for (int j = find; j < numOfPub - 1; j++) {
                pub_list[j] = pub_list[j + 1];
            }
            pub_list[numOfPub - 1] = nullptr;
            numOfPub--;
        }
    }
    void Update(IArticlePub* publisher, const string contents) {
        this->recent_article_pub = publisher;
        this->recent_article_contents = contents;
        PrintContents();
    }

    void PrintContents() {
        cout << "Sub (" << this->sub_name << "," << this->sub_id << ")'s latest subscribed news is \"" << this->recent_article_contents << "\" by " << this->recent_article_pub->getPubName() << endl;
    }

    string getSubName() {
        return this->sub_name;
    }

    int getSubID() {
        return this->sub_id;
    }

    int getPubSize() {
        return this->numOfPub;
    }
    void PrintAllPub() {
        for (int i = 0; i < numOfPub; i++) {
            cout << "[" << pub_list[i]->getPubName() << "," << pub_list[i]->getPubID() << "]";
        }
        cout << endl;
    }
};

int IArticleSub::static_sub_counter = 0;

IArticlePub::IArticlePub(const string name) {
    this->pub_name = name;
    this->pub_id = ++IArticlePub::static_pub_counter;
    for (int i = 0; i < 5; i++) {
        sub_list[i] = nullptr;
    }
    cout << "[Constructor]New Pub Created: (" << this->getPubName() << "," << this->getPubID() << ")" << endl;
}

IArticlePub::IArticlePub(const string name, const string con) {
    this->pub_name = name;
    this->recent_contents = con;
    this->pub_id = ++IArticlePub::static_pub_counter;
    for (int i = 0; i < 5; i++) {
        sub_list[i] = nullptr;
    }
    cout << "[Constructor]New Pub Created: (" << this->getPubName() << "," << this->getPubID() << ")" << endl;
}

IArticlePub::~IArticlePub() {
    cout << "IArticlePub Destructor called" << endl;
    for (int i = 0; i < numOfSub; i++) {
        sub_list[i]->DetachResponse(this);
    }
}

void IArticlePub::NotifyAttachResponse(IArticleSub* subscriber) {
    int find = -1;
    for (int i = 0; i < numOfSub; i++) {
        if (sub_list[i] == subscriber) {
            find = i;
        }
    }
    if (find != -1) {
        cout << "[ERROR]: already exists" << endl;
    }
    else {
        cout << "[Attach] Sub (" << subscriber->getSubName() << "," << subscriber->getSubID() << ") is attached to Pub (" << this->getPubName() << "," << this->getPubID() << ")" << endl;
        sub_list[numOfSub++] = subscriber;
    }
}

void IArticlePub::NotifyAttach(IArticleSub* subscriber) {
    int find = -1;
    for (int i = 0; i < numOfSub; i++) {
        if (sub_list[i] == subscriber) {
            find = i;
        }
    }
    if (find != -1) {
        cout << "[ERROR]: already exists" << endl;
    }
    else {
        cout << "[Attach] Sub (" << subscriber->getSubName() << "," << subscriber->getSubID() << ") is attached to Pub (" << this->getPubName() << "," << this->getPubID() << ")" << endl;
        sub_list[numOfSub++] = subscriber;
        subscriber->AttachResponse(this);
    }
}

void IArticlePub::NotifyDetach(IArticleSub* subscriber) {
    int find = -1;
    for (int i = 0; i < numOfSub; i++) {
        if (sub_list[i] == subscriber) {
            find = i;
        }
    }
    if (find == -1) {
        cout << "[ERROR]: There is no subscriber named" << subscriber->getSubName() << endl;
    }
    else {
        cout << "[Pub] (" << this->getPubName() << "," << this->getPubID() << ") detach [Sub] (" << subscriber->getSubName() << "," << subscriber->getSubID() << ")" << endl;
        for (int j = find; j < numOfSub - 1; j++) {
            sub_list[j] = sub_list[j + 1];
        }
        sub_list[numOfSub - 1] = nullptr;
        numOfSub--;
        subscriber->DetachResponse(this);
    }
}
void IArticlePub::NotifyDetachResponse(IArticleSub* subscriber) {
    int find = -1;
    for (int i = 0; i < numOfSub; i++) {
        if (sub_list[i] == subscriber) {
            find = i;
        }
    }
    if (find == -1) {
        cout << "[ERROR]: There is no subscriber named" << subscriber->getSubName() << endl;
    }
    else {
        cout << "[Pub] (" << this->getPubName() << "," << this->getPubID() << ") detach [Sub] (" << subscriber->getSubName() << "," << subscriber->getSubID() << ")" << endl;
        for (int j = find; j < numOfSub - 1; j++) {
            sub_list[j] = sub_list[j + 1];
        }
        sub_list[numOfSub - 1] = nullptr;
        numOfSub--;
    }
}
void IArticlePub::Notify() {
    for (int i = 0; i < numOfSub; i++) {
        sub_list[i]->Update(this, recent_contents);
    }
}
void IArticlePub::updatePubContents(string c) {
    this->recent_contents = c;
    Notify();
}
int IArticlePub::getPubID() {
    return this->pub_id;
}
string IArticlePub::getPubName() {
    return this->pub_name;
}
int IArticlePub::getSubSize() {
    return this->numOfSub;
}
void IArticlePub::PrintAllSub() {
    for (int i = 0; i < numOfSub; i++) {
        cout << "[" << sub_list[i]->getSubName() << "," << sub_list[i]->getSubID() << "]";
    }
    cout << endl;
}


int IArticlePub::static_pub_counter = 0;



class dgist_press : public IArticlePub {
public:
    dgist_press();
    dgist_press(const string con);
    void Event();
    void CheerUp();
    ~dgist_press();
};

dgist_press::dgist_press() : IArticlePub("DGIST") {
    cout << "dgist press constructor1 is called" << endl;
}

dgist_press::dgist_press(const string con) : IArticlePub("DGIST", con) {
    cout << "dgist press constructor2 is called" << endl;
}

dgist_press::~dgist_press() {
    cout << "DGIST PRESS is destructed" << endl;
}

void dgist_press::Event() {
    cout << "The Event is totally swindle" << endl;
}

void dgist_press::CheerUp() {
    updatePubContents("I Love you guys");
}



class BBC : public IArticlePub {
public:
    BBC();
    BBC(const string con);
    void Advertisement();
    void Event();
    ~BBC();
};


BBC::BBC() : IArticlePub("BBC") {
    cout << "BBC constructor1 is called" << endl;
}

BBC::BBC(const string con) : IArticlePub("BBC", con) {
    cout << "BBC constructor2 is called" << endl;
}

BBC::~BBC() {
    cout << "BBC is destructed" << endl;
}

void BBC::Advertisement() {
    cout << "BBC NEWS is coming soon!!" << endl;
}

void BBC::Event() {
    string sname;
    int sid = -1;
    for (int i = 0; i < 5; i++) {
        if (sub_list[i] != nullptr) {
            sname = sub_list[i]->getSubName();
            sid = sub_list[i]->getSubID();
            break;
        }
    }
    if (sid == -1) {
        cout << "[ERROR]: There is no subscribers" << endl;
    }
    cout << "The Event winner is (" << sname << "," << sid << ")" << endl;
}



class CNN : public IArticlePub {
public:
    CNN();
    CNN(const string con);
    void Event();
    ~CNN();
};

CNN::CNN() : IArticlePub("CNN") {
    cout << "CNN constructor1 is called" << endl;
}

CNN::CNN(const string con) : IArticlePub("CNN", con) {
    cout << "CNN constructor2 is called" << endl;
}

CNN::~CNN() {
    cout << "CNN is destructed" << endl;
}

void CNN::Event() {
    string sname;
    int sid = -1;
    for (int i = 4; i > -1; i--) {
        if (sub_list[i] != nullptr) {
            sname = sub_list[i]->getSubName();
            sid = sub_list[i]->getSubID();
            break;
        }
    }
    if (sid == -1) {
        cout << "[ERROR]: There is no subscribers" << endl;
    }
    cout << "The Event winner is (" << sname << "," << sid << ")" << endl;
}


int main() {
    dgist_press* dgistPub = new dgist_press(string("this is dgist pub"));
    BBC* bbcPub = new BBC();
    CNN* cnnPub = new CNN();

    //Jenny subscribe DGIST, BBC
    IArticleSub* jennySub = new IArticleSub("Jenny", dgistPub);
    *jennySub >> bbcPub; //Operator Overloading
    
    //Tom subscribe BBC, CNN
    IArticleSub* tomSub = new IArticleSub("Tom");
    *tomSub >> bbcPub; //Operator Overloading
    *tomSub >> cnnPub; //Operator Overloading
    
    //Kate subscribe DGIST, BBC, CNN
    IArticleSub* kateSub = new IArticleSub("Kate", dgistPub);
    *kateSub >> bbcPub; //Operator Overloading
    *kateSub >> bbcPub; //Operator Overloading
    *kateSub >> cnnPub; //Operator Overloading

    cout << "All Sub of (" << dgistPub->getPubName() << "," << dgistPub->getPubID() << "): ";
    dgistPub->PrintAllSub();

    cout << "All Sub of (" << bbcPub->getPubName() << "," << bbcPub->getPubID() << "): ";
    bbcPub->PrintAllSub();

    cout << "All Sub of (" << cnnPub->getPubName() << "," << cnnPub->getPubID() << "): ";
    cnnPub->PrintAllSub();

    bbcPub->Event();
    dgistPub->CheerUp();
    kateSub->Detach(bbcPub);

    cout << "All Pub of (" << jennySub->getSubName() << "," << jennySub->getSubID() << "): ";
    jennySub->PrintAllPub();

    cout << "All Pub of (" << tomSub->getSubName() << "," << tomSub->getSubID() << "): ";
    tomSub->PrintAllPub();
    
    cout << "All Pub of (" << kateSub->getSubName() << "," << kateSub->getSubID() << "): ";
    kateSub->PrintAllPub();

    cout << "=========DGIST Notify ===========" << endl;
    *dgistPub << "Welcome New DGIST students"; //Operator Overloading

    cout << "=========BBC Notify ===========" << endl;
    *bbcPub << "Mr. Son scored at Tottenham"; //Operator Overloading
    
    cout << "=========CNN Notify ===========" << endl;
    *cnnPub << "New York city celebrates Christmas"; //Operator Overloading
    
    cout << "=========DELETING [tomSub]===========" << endl;
    delete tomSub;

    cout << "=========DGIST Notify ===========" << endl;
    *dgistPub << "Welcome New DGIST students"; //Operator Overloading
    
    cout << "=========BBC Notify ===========" << endl;
    *bbcPub << "Mr. Son scored at Tottenham"; //Operator Overloading
    
    cout << "=========CNN Notify ===========" << endl;
    *cnnPub << "New York city celebrates Chirstmas"; //Operator Overloading
    
    cout << "=========Delete all others ===========" << endl;
    delete dgistPub;
    delete bbcPub;
    delete cnnPub;
    delete jennySub;
    //delete tomSub;
    delete kateSub;

    return 0;
}


