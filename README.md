# Repository with tasks from Stepic C++ course

##Topics completed:
- Unit tests (Google test framework used).\
    ./tests/


## Topics TODO
- Overload operator[][]
- Write simple iterator
- Multithreading (std::async and std::thread)
- Metaprogramming

- Compete README (add completed topics, search for other mistakes, add compile and launch instructions for console).

## Mistakes while making repository / doing tasks
- Did not create separate git branch for each topic.\
    There were problems when committing completed tasks if another task was already started, on which the difficulty arose.
- All test data is hardcoded.\
    If want to change or add some test data recompile of whole project is needed.
- Test logging occurs to stdout.\
    Better to write logs to some file.
- Executable for tests.
    Tests should be executed once after compilation, not at every launch.
 