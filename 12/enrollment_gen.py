import random
import string
words = open("/usr/share/dict/words").read().splitlines()
def gen_student(f):
    d = dict()
    for i in range(500):
        stu_num = ''.join(random.choice(string.digits) for _ in range(6))
        d['z5' + stu_num] = ' '.join(random.choice(words) for _ in range(random.randint(1,5)))
    for k,v in d.items():
        f.write(k + "," + v + "\n")
    return d

def gen_course(f):
    d = dict()
    for i in range(50):
        course_num = ''.join(random.choice(string.digits) for _ in range(4))
        d['COMP' + course_num] = ' '.join(random.choice(words) for _ in range(random.randint(4,10)))
    for k,v in d.items():
        f.write(k + "," + v + "\n")
    return d

def gen_enrollment(f, ss, cs):
    for s in ss:
        for _ in range(4):
            f.write(s + "," + random.choice(cs) + "\n")


sf = open('student.data', 'w')
cf = open('course.data','w')
ef = open('enrollment.data', 'w')

students = gen_student(sf)
courses = gen_course(cf)
gen_enrollment = gen_enrollment(ef, students.keys(), list(courses.keys()))
