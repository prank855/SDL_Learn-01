#pragma once

namespace plx {
    class Component {
    public:
        void virtual Init();
        void virtual Start();
        void virtual Update();
    };
};