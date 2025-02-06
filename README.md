# Threaded Prime Number Search

This program demonstrates essential threading concepts by creating a configurable number of threads, referred to as `x`, to search for prime numbers up to a specified limit, `y`, defined in a configuration file. It supports **two output modes**: [A1] *immediate output* (displaying thread ID and timestamp) and [A2] *batch output* (showing results only after all threads have finished). Additionally, the program implements **two task division methods**: [B1] *range-based division* and [B2] *per-number divisibility testing*. It also logs the start and end timestamps for each execution.

## The Four Variants
1. Search for prime numbers in a range and print them immediately. **[A1B1]**
2. Search for prime numbers in a range and print them at the end. **[A2B1]**
3. Search for prime numbers linearly and print them immediately. **[A1B2]**
4. Search for prime numbers linearly and print them at the end. **[A2B2]**

## Video Demonstration of the Four Variants
The demonstration of all variants are accessible in the following:
- Google Drive: 
- YouTube Link:

## Four Variants in the Directory
- Print Modes:
    - **Print Immediately** implemenation is in the `../Print/PrintImmediately.cpp`
    - **Print At The End** implementation is in the `../Print/PrintAtTheEnd.cpp`
- Task Division Methods:
    - **Range-Based Division** implementation is in the `../PrimeSearch/SearchRange.cpp`
    - **Per-Number Divisibility Testing** implemenation is in the `../PrimeSearch/SearchLinear.cpp`

The combination of these print modes and task division methods results to four variants which is implemented in the following functions: `executeVariant1`, `executeVariant2`, `executeVariant3`, `executeVariant4` respectively and can be found in the `../Variation/VariationManager.cpp`.

## Build and Compil Instructions
1. Ensure that you have a C compiler installed on your machine.
2. Clone the repository or download the Zip file.
    ```
    https://github.com/axvolkzki/STDISCM-P1-Threaded-Prime-Number-Search.git
    ```
3. Manually run the program on your local machine by navigating to the Project directory where the main.c is located.
    ```
    cd STDISCM-P1-Threaded-Prime-Number-Search
    ```
4. Compile the program.
    ```
    g++ -std=c++20 Config/GlobalConfig.cpp Helper/Colors.cpp Menu/MainMenu.cpp PrimeSearch/ASearch.cpp PrimeSearch/SearchLinear.cpp PrimeSearch/SearchRange.cpp Print/PrintAtTheEnd.cpp Print/PrintImmediately.cpp Variation/VariationManager.cpp main.cpp -o main.exe
    ```
5. Run the executable file.
    ```
    ./main.exe
    ```

## Developer
ABENOJA, Amelia Joyce L.     STDISCM - S14

