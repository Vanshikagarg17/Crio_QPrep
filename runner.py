# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
import argparse
import os
import sys
import git
from git import Repo
import urllib.request

#TODO: handle timeout
#TODO: handle whitespace mismatch on output files

TIMEOUT_FOR_ONE_JAVA_TESTCASE = 7.0

import subprocess
def cmd_timeout(cmds, timeout=2000):
    p = subprocess.Popen(cmds)
    try:
        p.wait(my_timeout)
    except subp.TimeoutExpired:
        p.kill()
        return 'Timeout'

    print(p)

def remove_whitespace(file_x):
    f = open(file_x, 'r+')
    lines = f.readlines()
    f.close()

    lines = list(filter(lambda x: x.strip() != '', lines))
    lines = list(map(lambda x: x.strip(), lines))
    return lines

def filecompare_ignore_whitespace(file1, file2, debug):
    c1 = remove_whitespace(file1)
    c2 = remove_whitespace(file2)

    if debug:
        print("=" * 100)
        print("Actual  :", c1, "\n")
        print("Expected:", c2, "\n")
        print("=" * 100)

    return c1 == c2

def run_command_with_timeout(cmd, timeout_in_seconds):
    crio_path = os.getenv('PWD')
    new_path = crio_path
    if os.getenv("PYTHONPATH"):
        new_path = new_path + ":" + os.getenv('PYTHONPATH')
    ret = subprocess.call(cmd, shell=True, timeout=timeout_in_seconds, env= { 'PYTHONPATH' : new_path})
    return ret

def all_inc_directories(path, prefix):
    all_incs = []
    for root, directories, filenames in os.walk(path):
        for directory in directories:
            if directory == 'cpp':
                all_incs.append(prefix + os.path.join(root, directory))
    return all_incs

def run(name_of_the_problem, debug, lang):
    all_test_files = os.listdir(name_of_the_problem + '/tests/')

    evaluate_file = name_of_the_problem + '/evaluate.py'
    multiple_solution_possible = os.path.exists(evaluate_file)


    all_tests_passed = True

    full_file_name = {
            'c++' : "{}/{}.cpp".format(name_of_the_problem, name_of_the_problem),
            'java' : "{}/{}.java".format(name_of_the_problem, name_of_the_problem),
            'python' : "{}/{}.py".format(name_of_the_problem, name_of_the_problem)
            }

    assert lang in ['c++', 'java', 'python']

    print(full_file_name[lang])
    if not os.path.exists(full_file_name[lang]):
        print('Skipping tests: no file name {} not found'.format(full_file_name[lang]))
        return True

    if multiple_solution_possible:
        print('\n====== Multiple solutions =========\n')

    ret = 0

    inc_paths = ' '.join(all_inc_directories(os.getenv('PWD') + '/crio', '-I'))

    compile_cmds = {
            'c++' : 'cd {} && g++ -std=c++14 -Wall -Werror {} {}.cpp -o {}.out'.format(name_of_the_problem, inc_paths, name_of_the_problem, name_of_the_problem),
            'java': 'cd {} && javac -cp ../crio.jar {}.java'.format(name_of_the_problem, name_of_the_problem)
            }
    if lang in compile_cmds:
        compile_program = compile_cmds[lang]
        ret = os.system(compile_program)

    test_results = {}

    if ret != 0:
        return test_results

    all_test_files = sorted(all_test_files)

    for index in range(len(all_test_files)):
        file_name = all_test_files[index]
        if 'input-' in file_name:
            output_file_name = file_name.replace('input-', 'output-')
            test_name = file_name.replace('input-', 'test-')
            if output_file_name in all_test_files:
                actual_output_file = "actual-{}.txt".format(index)

                run_commands = {
                    'c++' : 'cd {} && ./{}.out < tests/{} > {}'.format(name_of_the_problem, name_of_the_problem, file_name, actual_output_file),
                    'java': 'cd {} && java -cp .:../crio.jar {} < tests/{} > {}'.format(name_of_the_problem, name_of_the_problem, file_name, actual_output_file),
                    'python': 'cd {} && python3 {}.py < tests/{} > {}'.format(name_of_the_problem, name_of_the_problem, file_name, actual_output_file)
                }
                cmd_to_run = run_commands[lang]
                try:
                    run_command_with_timeout(cmd_to_run, TIMEOUT_FOR_ONE_JAVA_TESTCASE)
                    passed = False
                    if multiple_solution_possible:
                        cmd = 'python3 {} {} {} {}'.format(evaluate_file, name_of_the_problem + '/tests/' + file_name, name_of_the_problem + '/tests/' + output_file_name, name_of_the_problem + '/' + actual_output_file)
                        proc = subprocess.run(cmd, shell=True)
                        passed = proc.returncode == 0
                    else:
                        passed = filecompare_ignore_whitespace(name_of_the_problem + '/{}'.format(actual_output_file), name_of_the_problem + '/tests/' + output_file_name, debug)

                    if passed:
                        print('%-25s : Passed' % (file_name))
                        test_results[test_name] = 'PASSED'
                    else:
                        print('%-25s : Failed' % (file_name))
                        test_results[test_name] = 'FAILED'
                        all_tests_passed = False
                    continue
                except subprocess.TimeoutExpired:
                    test_results[test_name] = 'TIMEDOUT'
                    all_tests_passed = False
                    print('%-25s: Timedout' % (file_name))
                except:
                    test_results[test_name] = 'RUNTIME_FAILURE'
                    all_tests_passed = False
                    print('Run time error')


    return all_tests_passed

def commit_msg(name_of_the_problem, submission_type, lang):
    return "[{}]:[{}]:[{}]".format(submission_type, name_of_the_problem, lang)

def commit(name_of_the_problem, lang, push=False):
    repo = Repo('.')
    repo.index.add([name_of_the_problem], force=False)
    # print(dir(repo.index))
    if push:
        repo.index.commit(commit_msg(name_of_the_problem, "Solved", lang))
        repo.remotes.origin.push()
    else:
        repo.index.commit(commit_msg(name_of_the_problem, "LocalTest", lang))

def get_submission_type_and_problem_id():
    repo = Repo('.')
    commits = list(repo.iter_commits('master', max_count=5))

    commit = commits[0]
    print(commit.message)
    lst = [x.strip('[]') for x in commit.message.split(":")]
    print(lst)
    submission = lst[0]
    problem_id = lst[1]
    return (submission, problem_id)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(prog='myprogram')
    parser.add_argument('-r', '--run', help='Run problem id', action='store_true')
    parser.add_argument('-s', '--submit', help='Submit problem id', action='store_true')
    parser.add_argument('-c', '--check-understanding', help='Check understanding of problem id', action='store_true')
    parser.add_argument('-t', '--test-all', help='all assessment for all problems', action='store_true')
    parser.add_argument('-d', '--debug', help='print expected and actual output', action='store_true')
    parser.add_argument('--problem', help='name of the problem solved')
    parser.add_argument('--lang', help='language used', required=False)

    developer = False
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    # developer = True
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    if "crio.jar" not in os.listdir():
        url = "https://drive.google.com/uc?export=download&id=1HPgTA26cAOXeUj878FhL3k_rdnBhkHh_"
        with urllib.request.urlopen(url) as response, open("crio.jar", 'wb') as out_file:
            data = response.read()
            out_file.write(data)

    args = parser.parse_args()
    debug = False
    if args.debug:
        debug = True


    if args.lang is None:
        args.lang = 'java'

    allowed_languages = ['c++', 'java', 'python']
    if args.lang not in allowed_languages:
        print('Allowed languages are ', allowed_languages)
        sys.exit(1)

    failed_problems = []

    if args.test_all:
        all_problems = next(os.walk(os.getenv('PWD')))[1]

        try:
            all_problems.remove('.git')
            all_problems.remove('config')
            all_problems.remove('crio')
        except ValueError:
            pass

        all_passed = True
        for problem in all_problems:
            try:
                res = run(problem, debug, args.lang)
                all_passed = all_passed and res
                print(problem, ['FAILED','PASSED'][res])
                if not res:
                    failed_problems.append(problem)
            except:
                failed_problems.append(problem)
                pass

        print("All failed problems", failed_problems)
        if all_passed:
            sys.exit(0)
        else:
            sys.exit(1)

    dirs = os.listdir('.')
    if not args.problem in dirs:
        print(dirs)
        print('Error: Invalid problem id: %s', args.problem)
        sys.exit(1)

    if args.run:
        if not developer:
            commit(args.problem, args.lang, False)
        run(args.problem, debug, args.lang)

    if args.submit:
        run(args.problem, debug, args.lang)
        if not developer:
            commit(args.problem, args.lang, True)
        get_submission_type_and_problem_id()

    if args.check_understanding:
        print('check understanding')

# python3 runner.py --problem Addition --lang java --run
# python3 runner.py --problem Addition --lang c++ --run
# python3 runner.py --problem Addition --lang python --run
# python3 runner.py --problem Addition --lang java --submit
