#pragma once
namespace rz {

template <class State, State initState = State::IDLE>
class StateMachine {
    public:
    StateMachine() : state(initState) {
    }

    ~StateMachine() = default;

    State getState() const {
        return state;
    }

    void setState(State newState) {
        state = newState;
    }

    private:
    State state;
};
} // namespace rz
