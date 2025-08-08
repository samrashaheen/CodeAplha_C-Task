#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
double gradeToPoint(string grade){
    if(grade=="A"||grade=="a")return 4.0;
    else if(grade=="A-"||grade=="a-")return 3.7;
    else if(grade=="B+"||grade=="b+")return 3.3;
    else if(grade=="B"||grade=="b")return 3.0;
    else if(grade=="B-"||grade=="b-")return 2.7;
    else if(grade=="C+"||grade=="c+")return 2.3;
    else if(grade=="C"||grade=="c")return 2.0;
    else if(grade=="C-"||grade=="c-")return 1.7;
    else if(grade=="D+"||grade=="d+")return 1.3;
    else if(grade=="D"||grade=="d")return 1.0;
    else return 0.0;
}
int main(){
    int numCourses;
    double totalCredits=0,totalGradePoints=0;
    cout<<"===== CGPA Calculator ====="<<endl;
    cout<<"Enter the number of courses: ";
    cin>>numCourses;
    for(int i=1;i<=numCourses;i++){
        string grade;
        double creditHours;
        cout<<"\nCourse "<<i<<" grade (A, B+, C, etc.): ";
        cin>>grade;
        cout<<"Credit hours for this course: ";
        cin>>creditHours;
        double gradePoint=gradeToPoint(grade);
        double coursePoints=gradePoint*creditHours;
        cout<<"Grade points for this course: "<<coursePoints<<endl;
        totalCredits+=creditHours;
        totalGradePoints+=coursePoints;
    }
    double semesterGPA=totalGradePoints/totalCredits;
    cout<<fixed<<setprecision(2);
    cout<<"\nTotal Credits: "<<totalCredits;
    cout<<"\nTotal Grade Points: "<<totalGradePoints;
    cout<<"\nSemester GPA: "<<semesterGPA;
    cout<<"\nOverall CGPA: "<<semesterGPA<<endl;
    return 0;
}
