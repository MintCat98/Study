#include <iostream>
#include <string>
#include "dgist_press.h"
#include "BBC.h"
#include "CNN.h"

using namespace std;

int main() {
	dgist_press* dgistPub = new dgist_press(string("this is dgist pub"));
	BBC* bbcPub = new BBC();
	CNN* cnnPub = new CNN();
	IArticlePub* cnnPub_upcasting = cnnPub;

	//Jenny subscribe DGIST, BBC
	IArticleSub* jennySub = new IArticleSub("Jenny", dgistPub);
	bbcPub->NotifyAttach(jennySub);
	
	//Tom subscribe BBC, CNN
	IArticleSub* tomSub = new IArticleSub("Tom");
	bbcPub->NotifyAttach(tomSub);
	cnnPub_upcasting->NotifyAttach(tomSub);
	
	//Kate subscribe DGIST, BBC, CNN
	IArticleSub* kateSub = new IArticleSub("Kate", dgistPub);
	bbcPub->NotifyAttach(kateSub);
	cnnPub_upcasting->NotifyAttach(kateSub);
	
	cout << "All Sub of (" << dgistPub->getPubName() << "," << dgistPub->getPubID() << "): ";
	dgistPub->PrintAllSub();
	
	cout << "All Sub of (" << bbcPub->getPubName() << "," << bbcPub->getPubID() << "): ";
	bbcPub->PrintAllSub();
	
	cout << "All Sub of (" << cnnPub_upcasting->getPubName() << "," << cnnPub_upcasting -> getPubID() << "): ";
	cnnPub_upcasting->PrintAllSub();

	bbcPub->Event();
	cnnPub_upcasting->Event();
	dgistPub->Event();
	dgistPub->CheerUp();
	kateSub->Detach(bbcPub);

	cout << "All Pub of (" << jennySub->getSubName() << "," << jennySub->getSubID() << "): ";
	jennySub->PrintAllPub();
	
	cout << "All Pub of (" << tomSub->getSubName() << "," << tomSub->getSubID() << "): ";
	tomSub->PrintAllPub();
	
	cout << "All Pub of (" << kateSub->getSubName() << "," << kateSub->getSubID() << "): ";
	kateSub->PrintAllPub();

	cout << "=========DGIST Notify ===========" << endl;
	dgistPub->updatePubContents("Welcome New DGIST students");
	
	cout << "=========BBC Notify ===========" << endl;
	bbcPub->updatePubContents("Mr. Son scored at Tottenham");
	
	cout << "=========CNN Notify ===========" << endl;
	cnnPub_upcasting->updatePubContents("New York city celebrates Christmas");
	
	cout << "=========DELETING [tomSub]===========" << endl;
	delete tomSub;
	
	cout << "=========DGIST Notify ===========" << endl;
	dgistPub->updatePubContents("Welcome New DGIST students");
	
	cout << "=========BBC Notify ===========" << endl;
	bbcPub->updatePubContents("Mr. Son scored at Tottenham");
	
	cout << "=========CNN Notify ===========" << endl;
	cnnPub_upcasting->updatePubContents("New York city celebrates Christmas");

	cout << "=========Delete all others ===========" << endl;
	delete dgistPub;
	delete bbcPub;
	delete cnnPub;
	delete jennySub;
	delete kateSub;

	return 0;
}