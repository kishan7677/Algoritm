#include <iostream>
#include <functional>
using namespace std;

void first(function<void()> printFirst)
{
    printFirst(); // call the passed function
}

int main()
{
    first([]()
          { cout << "This is first!" << endl; });
    return 0;
}



/*Part Meaning
    function<void()>
        A function that returns nothing and takes no arguments
            printFirst The variable
            name(holds the passed function)
                first(...) A function that accepts a callback and likely calls it*/




    what is is lamda fun





   /* Awesome,
    Kishan !You're asking some **important and very practical** questions now. Let’s break it all down in a clean and beginner-friendly way:

            -- -

            ## 🧩 1. *
            *Lambda Functions in C++ – What
        & Why
    ? **

          ## # 🔹 What is a lambda function
          ?

          A * *lambda function * *is an * *anonymous function * * — a function * *without a name * *.

                                                                                                    Instead of writing
          :

```cpp
          int add(int a, int b)
{
    return a + b;
}
```

    You can write this :

```cpp auto add = [](int a, int b)
{
    return a + b;
};
```

    You can then call it like a normal function :

```cpp
        cout
    << add(2, 3); // Output: 5
```

    -- -

    ## # 🔹 Why use lambda functions
    ?

    -To **pass functions as arguments **(like in your `first(function<void()>)` example) - For **short,
    throwaway functions * *
        -For **callbacks **,
    **events **, **thread logic **, etc.- For **functional - style programming **and more readable code

                                        -- -

                                        ## 🧠 Basic Lambda Syntax
    :

```cpp[capture](parameters)->return_type{body};
```

    ## #Parts : |
                Part | Meaning |
                | -- -- -- -- -- -- --| -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -|
                | `[]` | Capture variables from outside |
                | `(int x)` | Parameters like a normal function |
                | `->int` | (optional) return type |
                | `
{
    ...
}
` | Function body |

    -- -

       ## # ✅ Example with Arguments and Return Type :

```cpp auto multiply = [](int a, int b) -> int
{
    return a * b;
};

cout << multiply(3, 4); // Output: 12
```

    You can even **omit **the `->int` part because C++ can **infer **the return type :

```cpp auto multiply = [](int a, int b)
{
    return a * b;
};
```

    -- -

    ## 🧩 2. *
    *Passing Lambda Functions as Arguments **

     ## # 🔹 If it takes arguments :

    Change `function<void()>` to include parameters and return type.

    #### 🧪 Example : Lambda takes argument
```cpp
#include <iostream>
#include <functional>
                      using namespace std;

void doMath(function<int(int, int)> mathFunc)
{
    int result = mathFunc(10, 5);
    cout << "Result: " << result << endl;
}

int main()
{
    // Lambda with arguments and return value
    auto subtract = [](int a, int b) -> int
    {
        return a - b;
    };

    doMath(subtract); // Output: Result: 5
}
```

    -- -

    ## 🔄 Summary Table :

    |
    Type | Declaration | Use |
    | -- -- --| -- -- -- -- -- -- -| -- -- -|
    | No argument,
    no return | `function<void()>` | `[]()
{ cout << "Hello"; }` |
        | With arguments,
    no return | `function<void(int)>` | `[](int x)
{ cout << x; }` |
            | With arguments and
        return | `function<int(int, int)>` | `[](int a, int b)
{ return a + b; }` |

               -- -

                  ## ⚠️ Bonus : Capturing Variables

```cpp int x = 5;
auto showX = [x]()
{
    cout << x; // captures value of x
};
```

    You can also do :

    - `[&]` — capture all by reference - `[=]` — capture all by value - `[&x]` — capture x by reference - `[=, &y]` — capture everything by value,
    but y by reference

        -- -

        ## ✅ Quick Final Example :

```cpp
#include <iostream>
#include <functional>
    using namespace std;

void greet(function<string(string)> greetFunc)
{
    cout << greetFunc("Kishan") << endl;
}

int main()
{
    greet([](string name)
          { return "Hello " + name; });
}
```

🟩 Output :
``` Hello Kishan
```

    -- -

    Let me know if you'd like to go one level deeper into: - Captures(`mutable`, `[=]`, `[&]`) -
    Returning lambdas from functions
    -
    Using lambdas with `std::thread`, `std::sort`,
    etc.

        Want to try writing one together
        ?

*/




        cpaturing machanisms in lamda fun












/*

        Let's dive deep into the **capture mechanisms** in C++ lambda functions. Capturing lets your lambda access variables from the surrounding scope. You can choose whether to capture by value or by reference, and you can even mix these approaches. Here’s a detailed breakdown:

        -- -

        ##1. Basic Lambda Form Recap

        A lambda expression in C++ has this general syntax
        :

```cpp
            [capture](parameters)
                ->return_type{
                    // function body
                };
```

        - **Capture clause(`[...]`) : **Determines how variables from the surrounding scope are made available inside the lambda.

                                      -- -

                                      ##2. Capturing by Value : `[=]` and `[x]`

                                                                              ## #Capture All by Value : `[=]`

    -
    **What it does : **Every variable used within the lambda(that is available in the surrounding scope) is captured by value.- A copy of each variable is made
    and stored inside the lambda.

            - **Behavior : **Changes made to these variables inside the lambda do * *not**affect the original variables outside.Even if the lambda is invoked later,
    it will operate on the values stored at the moment of capture.

        - **Example : **

  ```cpp
                      int a = 10,
                          b = 20;
auto lambdaByValue = [=]()
{
    // a and b are captured by value
    // (i.e., copies of a = 10 and b = 20)
    cout << "Inside lambda (by value): " << a << ", " << b << "\n";
};
a = 30;          // Changing a after lambda is defined
lambdaByValue(); // Still prints "10, 20" because a copy was made
```

    ## #Capture Specific Variable by Value : `[x]`

    -
    **What it does : **You can also specify a single variable(or a list of variables) to capture by value.

    - **Example : **

  ```cpp
                  int x = 5;
auto showX = [x]()
{
    // x is captured by value
    cout << "Captured value: " << x << "\n";
};
x = 10;  // Changing x after capture does not affect the lambda
showX(); // Outputs: "Captured value: 5"
```

        -- -

        ##3. Capturing by Reference : `[&]` and `[&x]`

    ## #Capture All by Reference : `[&]`

    - **What it does : **Every variable used within the lambda is captured **by reference **.This means the lambda holds references to the original variables rather than a copy.

    - **Behavior : **Any changes made inside the lambda will directly affect the original variables.It is useful when you need the lambda to modify variables defined outside or
    reflect their most recent value.

        - **Example : **

  ```cpp int a = 10,
              b = 20;
auto lambdaByRef = [&]()
{
    // a and b are captured by reference
    a += 5; // Modifies the original a
    cout << "Inside lambda (by reference): " << a << ", " << b << "\n";
};
lambdaByRef();                                        // a becomes 15; prints "15, 20"
cout << "Outside lambda: " << a << ", " << b << "\n"; // a is now 15
```

        ## #Capture Specific Variable by Reference : `[&x]`

    - **What it does : **Only the specified variable is captured by reference.Other variables either are not captured or
    must be captured by some default if needed.

        - **Example : **

  ```cpp int x = 5;
auto showXByRef = [&x]()
{
    // x is captured by reference
    cout << "Captured by reference: " << x << "\n";
    x = 100; // Changing x here changes the outer variable
};
showXByRef();                            // Outputs: "Captured by reference: 5"
cout << "Outside lambda: " << x << "\n"; // x becomes 100
```

    -- -

    ##4. Mixed Captures : `[=, &y]`

    -
    **What it does : **You can mix capture modes.In `[=, &y]`: -**`[=]`** : By default,
    capture all used variables by value.- **`&y`** : Exception—capture variable `y` by reference.

            - **Use Case : **When you mostly want copies but need to modify or
        reflect changes in one particular variable.

            - **Example : **

  ```cpp int a = 5,
              y = 10;
auto lambdaMixed = [=, &y]()
{
    // a is captured by value (copy), y is captured by reference
    cout << "Inside lambda: a = " << a << ", y = " << y << "\n";
    // a = a + 1;  // this change would affect only the copy of a in lambda, not the outer a
    y = y + 20; // This will modify y in the outer scope
};
lambdaMixed();
cout << "Outside lambda: a = " << a << ", y = " << y << "\n";
// Expected: a remains 5, y becomes 30
```

    -- -

    ##5. Captures and Mutable Lambdas

        By default,
    lambdas that capture by value cannot modify the captured copies because they are considered `const` within the lambda body.If you need to modify them, you can make the lambda **mutable ** :

    -**Syntax : **Add the `mutable` keyword after the parameter list.

                                                                                                                                                               - **Example : **

  ```cpp int x = 5;
auto mutableLambda = [x]() mutable
{
    x += 10; // Allowed because of mutable; modifies the captured copy
    cout << "Inside mutable lambda: " << x << "\n";
};
mutableLambda();                         // Prints: "Inside mutable lambda: 15"
cout << "Outside lambda: " << x << "\n"; // x is still 5, unchanged
```

        -- -

        ##6. Recap and Comparison

        | Capture Syntax | Effect | When to use |
        | -- -- -- -- -- -- -- --| -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -| -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -|
        | `[=]` | Captures all used external variables by value(copies) | When you want a snapshot of variables and don't need to modify them.  | | `[&]` | Captures all used external variables by reference | When you need the lambda to modify external variables
    or always see the latest value.|
           | `[x]` | Captures variable `x` by value | When only specific variables need to be captured by value.|
           | `[&x]` | Captures variable `x` by reference | When only specific variables need to be captured by reference.|
           | `[=, &y]` | Captures all by value; exception for `y`, which is captured by reference | When most variables can be copied, but one or a few should be referenced.  |

---

## 7. Practical Considerations

- **Lifetime Issues:**
  When capturing by reference, make sure the referenced variables outlive the lambda's use. Otherwise, you risk accessing dangling references.

- **Performance:**
  Capturing by value involves copying. For small types (ints, doubles), this is trivial; for larger objects, be mindful of performance implications.

- **Safety:**
  When you don't want the lambda to accidentally change values from the outer scope, use capture-by-value or even make the lambda `const` (which is the default).

---

Understanding these capture mechanisms gives you powerful tools to write flexible and expressive inline functions. They are especially useful in contexts like callbacks for threading, event handling, or modifying elements in STL algorithms.

Feel free to ask if you need further examples or clarification on any point!*/