#ifndef IWINDOW_HPP 
#define IWINDOW_HPP 
#include <string>

namespace gooapi::win {

    class Tiwindow {
        public:
            Tiwindow() : Tiwindow(800, 600, "Nice Window") {}
            Tiwindow(unsigned int aWidth, unsigned int aHeight, const std::string& aTitle)
                            : mWidth(aWidth), mHeight(aHeight), mTitle(aTitle) {}

            virtual ~Tiwindow() {}
            virtual void pollEvents() = 0;

            bool shouldQuit() { return mShouldQuit; }
            void setShouldQuit() { mShouldQuit = true; };

            void windowSetup() {
                mInitaialized = initWindow();
                mWindowCreated = createWindow();

                if (!mInitaialized || !mWindowCreated)
                    std::exit(EXIT_FAILURE);
            }

            bool isInitalized() const { return mInitaialized; }
            bool isWindowCreated() const { return mWindowCreated; }

        protected:
            virtual bool initWindow() = 0;
            virtual bool createWindow() = 0;
            virtual void destroyWindow() = 0;

            unsigned int mWidth{0}, mHeight{0};
            std::string mTitle;   
            
            bool mInitaialized{false};
            bool mWindowCreated{false};

        private:
            bool mShouldQuit{false};
    };

}

#endif